/*
 * Copyright (C) 2017 Qihoo, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
*/

package com.example.jnidemo.client;

import android.os.IBinder;
import android.os.IInterface;
import android.os.RemoteException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public abstract class IMyServiceManager implements IInterface {
    private final static  String SERVER = "demoService";
    public final static  String DESCRIPTOR = "com.example.jnidemo";

    final static int HELLO = IBinder.FIRST_CALL_TRANSACTION ;
    final static int VERSION = HELLO+1;


    public static IMyServiceManager getInstance() {
        IMyServiceManager manager = null;

        try {
            Class serviceManagerClass = Class.forName("android.os.ServiceManager");
            Method method = serviceManagerClass.getMethod("getService", String.class);
            IBinder b = (IBinder) method.invoke(null, IMyServiceManager.SERVER);
            manager = asInterface(b);
        } catch (ClassNotFoundException | NoSuchMethodException | IllegalAccessException |
                InvocationTargetException e) {
            e.printStackTrace();
        }

        return manager;
    }

    static private IMyServiceManager asInterface(IBinder obj) {
        if (obj == null) {
            return null;
        }
        IMyServiceManager in = (IMyServiceManager) obj.queryLocalInterface(IMyServiceManager.DESCRIPTOR);
        if (in != null) {
            return in;
        }
        return new MyServiceProxy(obj);
    }

    public abstract void sayHello() throws RemoteException;
    public abstract int getVersion() throws RemoteException;

}
