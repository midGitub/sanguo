﻿//this source code was auto-generated by tolua#, do not modify it
using System;
using LuaInterface;

public class LuaInterface_LuaPropertyWrap
{
	public static void Register(LuaState L)
	{
		L.BeginClass(typeof(LuaInterface.LuaProperty), typeof(System.Object));
		L.RegFunction("Get", Get);
		L.RegFunction("Set", Set);
		L.RegFunction("__tostring", ToLua.op_ToString);
		L.EndClass();
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int Get(IntPtr L)
	{
		try
		{			
			LuaInterface.LuaProperty obj = (LuaInterface.LuaProperty)ToLua.CheckObject(L, 1, typeof(LuaInterface.LuaProperty));            
            return obj.Get(L);						
		}
		catch (Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int Set(IntPtr L)
	{
		try
		{			
            LuaInterface.LuaProperty obj = (LuaInterface.LuaProperty)ToLua.CheckObject(L, 1, typeof(LuaInterface.LuaProperty));            
            return obj.Set(L);
        }
        catch (Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}
}

