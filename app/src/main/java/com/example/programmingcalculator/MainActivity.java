package com.example.programmingcalculator;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;

import com.example.programmingcalculator.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("cppSource");
    }

    private ActivityMainBinding binding;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
    }

    public void onClickBinary(View view){
        binding.outputField.setText(decimalToBinary(binding.inputField.getText().toString()));
    }

    public void onClickDecimal(View view){
        binding.outputField.setText(binaryToDecimal(binding.inputField.getText().toString()));
    }

    public void onClickAscii(View view){
        binding.outputField.setText(asciiToDecimal(binding.inputField.getText().toString()));
    }

    public native String decimalToBinary(String str);
    public native String asciiToDecimal(String str);
    public native String binaryToDecimal(String str);
}