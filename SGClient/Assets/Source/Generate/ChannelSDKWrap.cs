﻿//this source code was auto-generated by tolua#, do not modify it
using System;
using LuaInterface;

public class ChannelSDKWrap
{
	public static void Register(LuaState L)
	{
		L.BeginClass(typeof(ChannelSDK), typeof(UnityEngine.MonoBehaviour));
		L.RegFunction("init", init);
		L.RegFunction("onInit", onInit);
		L.RegFunction("login", login);
		L.RegFunction("logout", logout);
		L.RegFunction("pay", pay);
		L.RegFunction("setExtendData", setExtendData);
		L.RegFunction("__eq", op_Equality);
		L.RegFunction("__tostring", ToLua.op_ToString);
		L.RegVar("Instance", get_Instance, null);
		L.EndClass();
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int init(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			ChannelSDK obj = (ChannelSDK)ToLua.CheckObject(L, 1, typeof(ChannelSDK));
			string arg0 = ToLua.CheckString(L, 2);
			obj.init(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int onInit(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			ChannelSDK obj = (ChannelSDK)ToLua.CheckObject(L, 1, typeof(ChannelSDK));
			string arg0 = ToLua.CheckString(L, 2);
			obj.onInit(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int login(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			ChannelSDK obj = (ChannelSDK)ToLua.CheckObject(L, 1, typeof(ChannelSDK));
			string arg0 = ToLua.CheckString(L, 2);
			obj.login(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int logout(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			ChannelSDK obj = (ChannelSDK)ToLua.CheckObject(L, 1, typeof(ChannelSDK));
			string arg0 = ToLua.CheckString(L, 2);
			obj.logout(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int pay(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			ChannelSDK obj = (ChannelSDK)ToLua.CheckObject(L, 1, typeof(ChannelSDK));
			string arg0 = ToLua.CheckString(L, 2);
			obj.pay(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int setExtendData(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			ChannelSDK obj = (ChannelSDK)ToLua.CheckObject(L, 1, typeof(ChannelSDK));
			string arg0 = ToLua.CheckString(L, 2);
			obj.setExtendData(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int op_Equality(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			UnityEngine.Object arg0 = (UnityEngine.Object)ToLua.ToObject(L, 1);
			UnityEngine.Object arg1 = (UnityEngine.Object)ToLua.ToObject(L, 2);
			bool o = arg0 == arg1;
			LuaDLL.lua_pushboolean(L, o);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_Instance(IntPtr L)
	{
		try
		{
			ToLua.Push(L, ChannelSDK.Instance);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}
}
