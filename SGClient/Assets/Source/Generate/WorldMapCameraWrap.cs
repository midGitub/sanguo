﻿//this source code was auto-generated by tolua#, do not modify it
using System;
using LuaInterface;

public class WorldMapCameraWrap
{
	public static void Register(LuaState L)
	{
		L.BeginClass(typeof(WorldMapCamera), typeof(Camera2D));
		L.RegFunction("__eq", op_Equality);
		L.RegFunction("__tostring", ToLua.op_ToString);
		L.RegVar("m_pWorldMap", get_m_pWorldMap, set_m_pWorldMap);
		L.RegVar("m_viewChangeSec", get_m_viewChangeSec, set_m_viewChangeSec);
		L.RegVar("m_viewChangeFrame", get_m_viewChangeFrame, set_m_viewChangeFrame);
		L.RegVar("IsCanMoved", get_IsCanMoved, set_IsCanMoved);
		L.EndClass();
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
	static int get_m_pWorldMap(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			WorldMapCamera obj = (WorldMapCamera)o;
			WorldMap ret = obj.m_pWorldMap;
			ToLua.Push(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index m_pWorldMap on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_m_viewChangeSec(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			WorldMapCamera obj = (WorldMapCamera)o;
			float ret = obj.m_viewChangeSec;
			LuaDLL.lua_pushnumber(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index m_viewChangeSec on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_m_viewChangeFrame(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			WorldMapCamera obj = (WorldMapCamera)o;
			float ret = obj.m_viewChangeFrame;
			LuaDLL.lua_pushnumber(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index m_viewChangeFrame on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_IsCanMoved(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			WorldMapCamera obj = (WorldMapCamera)o;
			bool ret = obj.IsCanMoved;
			LuaDLL.lua_pushboolean(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index IsCanMoved on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_m_pWorldMap(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			WorldMapCamera obj = (WorldMapCamera)o;
			WorldMap arg0 = (WorldMap)ToLua.CheckUnityObject(L, 2, typeof(WorldMap));
			obj.m_pWorldMap = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index m_pWorldMap on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_m_viewChangeSec(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			WorldMapCamera obj = (WorldMapCamera)o;
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			obj.m_viewChangeSec = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index m_viewChangeSec on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_m_viewChangeFrame(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			WorldMapCamera obj = (WorldMapCamera)o;
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			obj.m_viewChangeFrame = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index m_viewChangeFrame on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_IsCanMoved(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			WorldMapCamera obj = (WorldMapCamera)o;
			bool arg0 = LuaDLL.luaL_checkboolean(L, 2);
			obj.IsCanMoved = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index IsCanMoved on a nil value" : e.Message);
		}
	}
}

