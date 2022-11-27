package io.github.maihd.vectormath_unit_tests_android

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import io.github.maihd.vectormath_unit_tests_android.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = if (runAllTestCases()) "Test Succeed!" else "Test failed";
    }

    /**
     * A native method that is implemented by the 'vectormath_unit_tests_android' native library,
     * which is packaged with this application.
     */
    external fun runAllTestCases(): Boolean

    companion object {
        // Used to load the 'vectormath_unit_tests_android' library on application startup.
        init {
            System.loadLibrary("vectormath_unit_tests_android")
        }
    }
}