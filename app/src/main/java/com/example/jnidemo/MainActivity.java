package com.example.jnidemo;

import android.app.Activity;
import android.os.Bundle;
import android.os.RemoteException;
import android.util.Log;
import android.view.View;
import android.widget.Button;

import com.example.jnidemo.client.IMyServiceManager;

public class MainActivity extends Activity {
    final static String TAG = "ly-s";
    Button binder;
    IMyServiceManager iClientManager=null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        iClientManager= IMyServiceManager.getInstance();
        initView();
        initJni();
    }



    private void initJni() {
        JniUtils jniUtils=new JniUtils();
        jniUtils.initJNI();
    }

    private void initView() {
        binder = findViewById(R.id.binder);
        binder.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                try {
                    iClientManager.sayHello();
                    Log.i(TAG,"version="+iClientManager.getVersion());
                } catch (RemoteException e) {
                    e.printStackTrace();
                }
            }
        });
    }

}
