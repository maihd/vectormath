const types = require("./types.json");
const functions = require("./functions.json");

function haxeifyName(name) {
    // Special names
    switch (name) {
        case "conj":
            return "conjugate";

        case "isclose":
            return "isClose";
        
        case "lensqr":
            return "lengthSqr";
        
        case "distsqr":
            return "distanceSqr";
    }

    const words = name.split("_");
    return words[0] + words.slice(1).map(word => word.charAt(0).toUpperCase() + word.substring(1)).join("");
}

function cppTypeToHaxe(name) {
    if (types[name]) {
        return types[name].haxeName;
    }

    const typeConvertList = {
        "int": "Int32",
        "int32_t": "Int32",

        "unsigned int": "UInt32",
        "uint32_t": "UInt32",

        "float": "Float32",
        "bool": "Bool"
    };
    if (typeConvertList[name]) {
        return typeConvertList[name];
    }

    return name;
}

function generateHaxeCode(nativeName, typeDefine) {
    let content = "";
    
    // Headers
    content += "package vectormath;\n\n";

    content += "#if cxx\n";
    content += "import cxx.num.Int32;\n";
    content += "import cxx.num.UInt32;\n";
    content += "import cxx.num.Float32;\n";
    content += "#elseif cpp\n";
    content += "import cpp.Int32;\n";
    content += "import cpp.UInt32;\n";
    content += "import cpp.Float32;\n";
    // content += "#elseif hl\n";
    // content += "private typedef Int32 = Int;\n";
    // content += "private typedef UInt32 = UInt;\n";
    // content += "private typedef Float32 = hl.F32;\n";
    content += "#end\n";

    content += "\n";

    // DataType
    // Metadata
    content += "@:valueType\n";
    content += "@:structAccess\n";
    content += "@:include(\"vectormath.h\")\n";
    content += "@:native(\"" + nativeName + "\")\n";

    // Class Declare
    content += "extern class " + typeDefine.haxeName + "Data\n";
    content += "{\n";

    if (typeDefine.kind === "Vector") {
        // Fields
        const fieldNames = [ "x", "y", "z", "w" ];
        for (let i = 0; i < typeDefine.length; i++) {
            content += "    public var " + fieldNames[i] + ": " + typeDefine.componentType + ";\n";
        }
    } else if (typeDefine.kind === "Matrix") {
        // Fields
        for (let i = 0; i < typeDefine.rows; i++) {
            for (let j = 0; j < typeDefine.cols; j++) {
                content += "    public var m" + i.toString() + j.toString() + ": " + typeDefine.componentType + ";\n";
            }

            if (i != typeDefine.rows - 1) {
                content += "\n";
            }
        }
    } else {
        throw new Error("Unsupported kind: " + typeDefine.kind);
    }

    content += "}\n";
    content += "\n";

    // AbstractType
    // Metadata
    content += "@:foward\n";
    if (typeDefine.swizzle) {
        content += "@:build(vectormath.Swizzle.generateFields(" + typeDefine.length + "))\n";
    }

    // Abstract Declare
    content += "extern abstract " + typeDefine.haxeName + "(" + typeDefine.haxeName + "Data)\n";
    content += "{\n";

    if (typeDefine.kind === "Vector") {
        // Variables

        // content += "    //\n";
        // content += "    // Variables\n";
        // content += "    //\n\n";

        const fieldNames = [ "x", "y", "z", "w" ];
        // for (let i = 0; i < typeDefine.length; i++) {
        //     content += "    public var " + fieldNames[i] + "(get, set): " + typeDefine.componentType + ";\n";
        //     content += "    inline function get_" + fieldNames[i] + "() return this." + fieldNames[i] + ";\n";
        //     content += "    inline function set_" + fieldNames[i] + "(v: " + typeDefine.componentType + ") return this." + fieldNames[i] + " = v;\n";

        //     if (i != typeDefine.length - 1) {
        //         content += "\n";
        //     } 
        // }

        // content += "\n";

        // Constructors
        if (typeDefine.hasConstructor) {
            content += "    //\n";
            content += "    // Constructors\n";
            content += "    //\n\n";

            content += "    @:native(\"" + nativeName + "_new\")\n";
            content += "    @:overload(function (): " + typeDefine.haxeName + " {})\n";
            content += "    @:overload(function (s: " + typeDefine.componentType + "): " + typeDefine.haxeName + " {})\n";
            content += "    public function new("

            for (let i = 0; i < typeDefine.length; i++) {
                content += fieldNames[i] + ": " + typeDefine.componentType;
                if (i !== typeDefine.length - 1) {
                    content += ", ";
                }
            }

            content += ");\n"
            content += "\n";
        }

        // Operators

        if (typeDefine.operator) {
            content += "    //\n";
            content += "    // Operators\n";
            content += "    //\n\n";

            const operators = [
                { 
                    name: "neg",
                    haxeName: "-A",
                    params: [
                        {
                            name: "v",
                            type: typeDefine.haxeName
                        },
                    ],
                },
                { 
                    name: "add",
                    haxeName: "A + B",
                    params: [
                        {
                            name: "a",
                            type: typeDefine.haxeName
                        },
                        {
                            name: "b",
                            type: typeDefine.haxeName
                        },
                    ],
                },
                { 
                    name: "sub",
                    haxeName: "A - B",
                    params: [
                        {
                            name: "a",
                            type: typeDefine.haxeName
                        },
                        {
                            name: "b",
                            type: typeDefine.haxeName
                        },
                    ],
                },
                { 
                    name: "mul",
                    haxeName: "A * B",
                    params: [
                        {
                            name: "a",
                            type: typeDefine.haxeName
                        },
                        {
                            name: "b",
                            type: typeDefine.haxeName
                        },
                    ],
                },
                { 
                    name: "div",
                    haxeName: "A / B",
                    params: [
                        {
                            name: "a",
                            type: typeDefine.haxeName
                        },
                        {
                            name: "b",
                            type: typeDefine.haxeName
                        },
                    ],
                },
                { 
                    name: "add1",
                    haxeName: "A + B",
                    commutative: true,
                    params: [
                        {
                            name: "a",
                            type: typeDefine.haxeName
                        },
                        {
                            name: "b",
                            type: "Float32"
                        },
                    ],
                },
                { 
                    name: "sub1",
                    haxeName: "A - B",
                    commutative: true,
                    params: [
                        {
                            name: "a",
                            type: typeDefine.haxeName
                        },
                        {
                            name: "b",
                            type: "Float32"
                        },
                    ],
                },
                { 
                    name: "mul1",
                    haxeName: "A * B",
                    commutative: true,
                    params: [
                        {
                            name: "a",
                            type: typeDefine.haxeName
                        },
                        {
                            name: "b",
                            type: "Float32"
                        },
                    ],
                },
                { 
                    name: "div1",
                    haxeName: "A / B",
                    commutative: true,
                    params: [
                        {
                            name: "a",
                            type: typeDefine.haxeName
                        },
                        {
                            name: "b",
                            type: "Float32"
                        },
                    ],
                },
                {
                    name: "equal",
                    haxeName: "A == B",
                    params: [
                        {
                            name: "a",
                            type: typeDefine.haxeName
                        },
                        {
                            name: "b",
                            type: typeDefine.haxeName
                        },
                    ],
                },
                {
                    name: "not_equal",
                    haxeName: "A != B",
                    params: [
                        {
                            name: "a",
                            type: typeDefine.haxeName
                        },
                        {
                            name: "b",
                            type: typeDefine.haxeName
                        },
                    ],
                }
            ];
            
            for (const operator of operators) {
                content += "    @:op(" + operator.haxeName + ")\n";

                if (operator.commutative) {
                    content += "    @:commutative\n";
                }

                content += "    @:native(\"" + nativeName + "_" + operator.name + "\")\n";
                content += "    public extern static function " + haxeifyName(operator.name) + "(";
                
                content += operator.params.map(param => param.name + ": " + param.type).join(", ");
                content += ") : " + typeDefine.haxeName + ";\n";
            
                content += "\n";
            }
        }
        
        // Static functions
        const typeFunctions = functions[nativeName];
        if (typeFunctions) {
            content += "    //\n";
            content += "    // Functions\n";
            content += "    //\n\n";

            for (const functionDefine of typeFunctions) {
                const name = functionDefine.name.substring(functionDefine.name.indexOf("_") + 1);
                
                // Skipping
                if (typeDefine.skipFunctions.includes(name)) {
                    continue;
                }

                const haxeName = haxeifyName(name);
                
                content += "    @:native(\"" + functionDefine.name + "\")\n";
                content += "    public extern static function " + haxeName + "(";
                
                content += functionDefine.params.map(param => param.name + ": " + cppTypeToHaxe(param.type)).join(", ");

                content += ") : " + cppTypeToHaxe(functionDefine.returnType) + ";\n";
                
                content += "\n";
            }
        }
        
        content += "    // End\n";
    } else if (typeDefine.kind === "Matrix") {
        // Variables

        // Constructors
        if (typeDefine.hasConstructor) {
            content += "    //\n";
            content += "    // Constructors\n";
            content += "    //\n\n";

            content += "    @:native(\"" + nativeName + "_new\")\n";
            content += "    @:overload(function (): " + typeDefine.haxeName + " {})\n";
            content += "    @:overload(function (s: " + typeDefine.componentType + "): " + typeDefine.haxeName + " {})\n";
            content += "    public function new("

            for (let i = 0; i < typeDefine.rows; i++) {
                for (let j = 0; j < typeDefine.cols; j++) {
                    content += "m" + i.toString() + j.toString() + ": " + typeDefine.componentType;

                    if (j != typeDefine.cols - 1) {
                        content += ", ";
                    }
                }

                if (i != typeDefine.rows - 1) {
                    content += ", ";
                }
            }

            content += ");\n"
            content += "\n";
        }

        // Operators

        // Static functions
        const typeFunctions = functions[nativeName];
        if (typeFunctions) {
            content += "    //\n";
            content += "    // Functions\n";
            content += "    //\n\n";

            for (const functionDefine of typeFunctions) {
                const name = functionDefine.name.substring(functionDefine.name.indexOf("_") + 1);
                
                // Skipping
                if (typeDefine.skipFunctions.includes(name)) {
                    continue;
                }

                const haxeName = haxeifyName(name);
                
                content += "    @:native(\"" + functionDefine.name + "\")\n";
                content += "    public extern static function " + haxeName + "(";
                
                content += functionDefine.params.map(param => param.name + ": " + cppTypeToHaxe(param.type)).join(", ");

                content += ") : " + cppTypeToHaxe(functionDefine.returnType) + ";\n";
                
                content += "\n";
            }
        }
        
        content += "    // End\n";
    } else {
        throw new Error("Unsupported kind: " + typeDefine.kind);
    }

    content += "}\n";

    return content;
}

// Generate bindings

const fs = require("fs");
const path = require("path");

for (const typeName in types) {
    const typeDefine = types[typeName];
    const filePath = path.join(__dirname, "vectormath", typeDefine.haxeName + ".hx");
    const fileData = generateHaxeCode(typeName, typeDefine);
    fs.writeFile(filePath, fileData, () => {
        console.log("Type " + typeName + " bindings written to: " + filePath);
    });
}