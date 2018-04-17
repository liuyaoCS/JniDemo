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
import android.os.Parcel;
import android.os.RemoteException;



public class MyServiceProxy extends IMyServiceManager {
    private IBinder mRemote = null;

    public MyServiceProxy(IBinder remote) {
        mRemote = remote;
    }

    public IBinder asBinder() {
        return mRemote;
    }

    @Override
    public void sayHello() throws RemoteException {
        Parcel data = Parcel.obtain();
        Parcel reply = Parcel.obtain();
        try {
            data.writeInterfaceToken(DESCRIPTOR);
            mRemote.transact(HELLO, data, reply, 0);
        } finally {
            data.recycle();
            reply.recycle();
        }
    }

    @Override
    public int getVersion() throws RemoteException {
        Parcel data = Parcel.obtain();
        Parcel reply = Parcel.obtain();
        try {
            data.writeInterfaceToken(DESCRIPTOR);
            mRemote.transact(VERSION, data, reply, 0);
            return reply.readInt();
        } finally {
            data.recycle();
            reply.recycle();
        }
    }

}
