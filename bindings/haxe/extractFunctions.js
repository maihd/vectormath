const functionsTracker = {};

function filterFunctions(types, ast) {
    if (ast.kind !== "FunctionDecl") {
        return;
    }

    const typeName = ast.name.substring(0, ast.name.indexOf("_"));
    if (!types[typeName]) {
        return;
    }
    
    // Skip overloaded functions
    if (functionsTracker[ast.name]) {
        return;
    }

    functionsTracker[ast.name] = true;
    
    // Define
    const functionDefine = {
        name: ast.name,
        signature: ast.type.qualType,
        returnType: ast.type.qualType.substring(0, ast.type.qualType.indexOf("(")).trim(),
        params: []
    };

    // Parse params
    for (const innerAst of ast.inner) {
        if (innerAst.kind !== "ParmVarDecl") {
            continue;
        }

        functionDefine.params.push({
            name: innerAst.name,
            type: innerAst.type.qualType,
        });
    }

    return functionDefine;
}

function filterFunctionsPerTypes(allFunctions) {
    const functionsPerTypes = {};
    for (const functionDefine of allFunctions) {
        const typeName = functionDefine.name.substring(0, functionDefine.name.indexOf("_"));
        if (!functionsPerTypes[typeName]) {
            functionsPerTypes[typeName] = [];
        }

        functionsPerTypes[typeName].push(functionDefine);
    }

    return functionsPerTypes;
}

const targetFilePath = __dirname + "/../../include/vectormath/vectormath_scalar.h";

// Parse C file to AST with clang
let output = [];
const astDumpProcess = require("child_process").spawn("clang", ["-Xclang", "-ast-dump=json", targetFilePath], {
    cwd: __dirname,
    env: process.env,
    stdio: "pipe",
    encoding: "utf-8"
});
astDumpProcess.stdout.on("data", function (data) {
    output.push(data.toString());
});
astDumpProcess.stdout.on("close", function () {
    const types = require("./types.json");

    // Filter functions from AST
    const astRoot = JSON.parse(output.join(""));
    const allFunctions = astRoot.inner.map(x => filterFunctions(types, x)).filter(x => x);

    // Filter functions per modules
    const functionsPerTypes = filterFunctionsPerTypes(allFunctions);

    // Store to file for bindgen, because this task is heavy and need do only once (or after C/C++ code are changed)
    require("fs").writeFileSync(__dirname + "/functions.json", JSON.stringify(functionsPerTypes, null, 4));
});