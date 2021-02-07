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
        if(i == binding.inputModeDecimal.getId()){
            setVisible();
            binding.decimalBtn.setEnabled(false);
            binding.decimalBtn.setVisibility(View.INVISIBLE);
        }
        else if(i == binding.inputModeAscii.getId()){
            setVisible();
            binding.asciiBtn.setEnabled(false);
            binding.asciiBtn.setVisibility(View.INVISIBLE);
        }
        else if(i == binding.inputModeBinary.getId()){
            setVisible();
            binding.binaryBtn.setEnabled(false);
            binding.binaryBtn.setVisibility(View.INVISIBLE);
        }
        else {
            binding.firstRow.setEnabled(false);
            binding.firstRow.setVisibility(View.INVISIBLE);
        }
    }

    void enableAllButtons(){
        binding.binaryBtn.setEnabled(true);
        binding.binaryBtn.setVisibility(View.VISIBLE);
        binding.decimalBtn.setEnabled(true);
        binding.decimalBtn.setVisibility(View.VISIBLE);
        binding.asciiBtn.setEnabled(true);
        binding.asciiBtn.setVisibility(View.VISIBLE);
    }
    void setVisible(){
        binding.firstRow.setEnabled(true);
        binding.firstRow.setVisibility(View.VISIBLE);
        enableAllButtons();
    }

    public void onClickDecimal(View view){
        if(binding.inputModeAscii.isChecked())
            binding.outputField.setText(asciiToDecimal(binding.inputField.getText().toString()));
        else if(binding.inputModeBinary.isChecked())
            binding.outputField.setText(binaryToDecimal(binding.inputField.getText().toString()));
    }

    public void onClickAscii(View view){
        binding.outputField.setText(decimalToAscii(binding.inputField.getText().toString()));
    }

    public void onClickBinary(View view){
        binding.outputField.setText(decimalToBinary(binding.inputField.getText().toString()));
    }
    public void onClickHex(View view){

    }

    public native String decimalToBinary(String str);
    public native String decimalToAscii(String str);
    public native String asciiToDecimal(String str);
    public native String binaryToDecimal(String str);
    public native String asciiToHex(String str);
}