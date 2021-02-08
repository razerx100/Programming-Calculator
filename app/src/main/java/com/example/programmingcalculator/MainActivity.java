package com.example.programmingcalculator;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.RadioGroup;

import com.example.programmingcalculator.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity implements RadioGroup.OnCheckedChangeListener {
    static {
        System.loadLibrary("c-lib");
    }

    private ActivityMainBinding binding;
    private int inputModeId;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        binding.radioGroup.setOnCheckedChangeListener(this);

        binding.inputModeDecimal.toggle();
    }

    @Override
    public void onCheckedChanged(RadioGroup radioGroup, int i) {
        inputModeId = i;
    }

    public void onClickDecimal(View view){
        binding.outputField.setText(
                decimalButtonFunction(binding.inputField.getText().toString(), inputModeId));
    }

    public void onClickAscii(View view){
        binding.outputField.setText(
                asciiButtonFunction(binding.inputField.getText().toString(), inputModeId));
    }

    public void onClickBinary(View view){
        binding.outputField.setText(
                binaryButtonFunction(binding.inputField.getText().toString(), inputModeId));
    }
    public void onClickHex(View view){
        binding.outputField.setText(
                hexButtonFunction(binding.inputField.getText().toString(), inputModeId));
    }

    public native String binaryButtonFunction(String str, int inputId);
    public native String asciiButtonFunction(String str, int inputId);
    public native String decimalButtonFunction(String str, int inputId);
    public native String hexButtonFunction(String str, int inputId);
}