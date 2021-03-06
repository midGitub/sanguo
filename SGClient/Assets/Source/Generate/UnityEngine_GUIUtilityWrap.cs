﻿//this source code was auto-generated by tolua#, do not modify it
using System;
using LuaInterface;

public class UnityEngine_GUIUtilityWrap
{
	public static void Register(LuaState L)
	{
		L.BeginClass(typeof(UnityEngine.GUIUtility), typeof(System.Object));
		L.RegFunction("GetControlID", GetControlID);
		L.RegFunction("GetStateObject", GetStateObject);
		L.RegFunction("QueryStateObject", QueryStateObject);
		L.RegFunction("ExitGUI", ExitGUI);
		L.RegFunction("GUIToScreenPoint", GUIToScreenPoint);
		L.RegFunction("ScreenToGUIPoint", ScreenToGUIPoint);
		L.RegFunction("ScreenToGUIRect", ScreenToGUIRect);
		L.RegFunction("RotateAroundPivot", RotateAroundPivot);
		L.RegFunction("ScaleAroundPivot", ScaleAroundPivot);
		L.RegFunction("New", _CreateUnityEngine_GUIUtility);
		L.RegFunction("__tostring", ToLua.op_ToString);
		L.RegVar("hotControl", get_hotControl, set_hotControl);
		L.RegVar("keyboardControl", get_keyboardControl, set_keyboardControl);
		L.RegVar("systemCopyBuffer", get_systemCopyBuffer, set_systemCopyBuffer);
		L.RegVar("hasModalWindow", get_hasModalWindow, null);
		L.EndClass();
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int _CreateUnityEngine_GUIUtility(IntPtr L)
	{
		try
		{
			int count = LuaDLL.lua_gettop(L);

			if (count == 0)
			{
				UnityEngine.GUIUtility obj = new UnityEngine.GUIUtility();
				ToLua.PushObject(L, obj);
				return 1;
			}
			else
			{
				return LuaDLL.luaL_throw(L, "invalid arguments to ctor method: UnityEngine.GUIUtility.New");
			}
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int GetControlID(IntPtr L)
	{
		try
		{
			int count = LuaDLL.lua_gettop(L);

			if (count == 1 && TypeChecker.CheckTypes(L, 1, typeof(UnityEngine.FocusType)))
			{
				UnityEngine.FocusType arg0 = (UnityEngine.FocusType)ToLua.ToObject(L, 1);
				int o = UnityEngine.GUIUtility.GetControlID(arg0);
				LuaDLL.lua_pushinteger(L, o);
				return 1;
			}
			else if (count == 2 && TypeChecker.CheckTypes(L, 1, typeof(int), typeof(UnityEngine.FocusType)))
			{
				int arg0 = (int)LuaDLL.lua_tonumber(L, 1);
				UnityEngine.FocusType arg1 = (UnityEngine.FocusType)ToLua.ToObject(L, 2);
				int o = UnityEngine.GUIUtility.GetControlID(arg0, arg1);
				LuaDLL.lua_pushinteger(L, o);
				return 1;
			}
			else if (count == 2 && TypeChecker.CheckTypes(L, 1, typeof(UnityEngine.FocusType), typeof(UnityEngine.Rect)))
			{
				UnityEngine.FocusType arg0 = (UnityEngine.FocusType)ToLua.ToObject(L, 1);
				UnityEngine.Rect arg1 = (UnityEngine.Rect)ToLua.ToObject(L, 2);
				int o = UnityEngine.GUIUtility.GetControlID(arg0, arg1);
				LuaDLL.lua_pushinteger(L, o);
				return 1;
			}
			else if (count == 2 && TypeChecker.CheckTypes(L, 1, typeof(UnityEngine.GUIContent), typeof(UnityEngine.FocusType)))
			{
				UnityEngine.GUIContent arg0 = (UnityEngine.GUIContent)ToLua.ToObject(L, 1);
				UnityEngine.FocusType arg1 = (UnityEngine.FocusType)ToLua.ToObject(L, 2);
				int o = UnityEngine.GUIUtility.GetControlID(arg0, arg1);
				LuaDLL.lua_pushinteger(L, o);
				return 1;
			}
			else if (count == 3 && TypeChecker.CheckTypes(L, 1, typeof(UnityEngine.GUIContent), typeof(UnityEngine.FocusType), typeof(UnityEngine.Rect)))
			{
				UnityEngine.GUIContent arg0 = (UnityEngine.GUIContent)ToLua.ToObject(L, 1);
				UnityEngine.FocusType arg1 = (UnityEngine.FocusType)ToLua.ToObject(L, 2);
				UnityEngine.Rect arg2 = (UnityEngine.Rect)ToLua.ToObject(L, 3);
				int o = UnityEngine.GUIUtility.GetControlID(arg0, arg1, arg2);
				LuaDLL.lua_pushinteger(L, o);
				return 1;
			}
			else if (count == 3 && TypeChecker.CheckTypes(L, 1, typeof(int), typeof(UnityEngine.FocusType), typeof(UnityEngine.Rect)))
			{
				int arg0 = (int)LuaDLL.lua_tonumber(L, 1);
				UnityEngine.FocusType arg1 = (UnityEngine.FocusType)ToLua.ToObject(L, 2);
				UnityEngine.Rect arg2 = (UnityEngine.Rect)ToLua.ToObject(L, 3);
				int o = UnityEngine.GUIUtility.GetControlID(arg0, arg1, arg2);
				LuaDLL.lua_pushinteger(L, o);
				return 1;
			}
			else
			{
				return LuaDLL.luaL_throw(L, "invalid arguments to method: UnityEngine.GUIUtility.GetControlID");
			}
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int GetStateObject(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			System.Type arg0 = (System.Type)ToLua.CheckObject(L, 1, typeof(System.Type));
			int arg1 = (int)LuaDLL.luaL_checknumber(L, 2);
			object o = UnityEngine.GUIUtility.GetStateObject(arg0, arg1);
			ToLua.Push(L, o);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int QueryStateObject(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			System.Type arg0 = (System.Type)ToLua.CheckObject(L, 1, typeof(System.Type));
			int arg1 = (int)LuaDLL.luaL_checknumber(L, 2);
			object o = UnityEngine.GUIUtility.QueryStateObject(arg0, arg1);
			ToLua.Push(L, o);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int ExitGUI(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 0);
			UnityEngine.GUIUtility.ExitGUI();
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int GUIToScreenPoint(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 1);
			UnityEngine.Vector2 arg0 = ToLua.ToVector2(L, 1);
			UnityEngine.Vector2 o = UnityEngine.GUIUtility.GUIToScreenPoint(arg0);
			ToLua.Push(L, o);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int ScreenToGUIPoint(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 1);
			UnityEngine.Vector2 arg0 = ToLua.ToVector2(L, 1);
			UnityEngine.Vector2 o = UnityEngine.GUIUtility.ScreenToGUIPoint(arg0);
			ToLua.Push(L, o);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int ScreenToGUIRect(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 1);
			UnityEngine.Rect arg0 = (UnityEngine.Rect)ToLua.CheckObject(L, 1, typeof(UnityEngine.Rect));
			UnityEngine.Rect o = UnityEngine.GUIUtility.ScreenToGUIRect(arg0);
			ToLua.PushValue(L, o);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int RotateAroundPivot(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 1);
			UnityEngine.Vector2 arg1 = ToLua.ToVector2(L, 2);
			UnityEngine.GUIUtility.RotateAroundPivot(arg0, arg1);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int ScaleAroundPivot(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			UnityEngine.Vector2 arg0 = ToLua.ToVector2(L, 1);
			UnityEngine.Vector2 arg1 = ToLua.ToVector2(L, 2);
			UnityEngine.GUIUtility.ScaleAroundPivot(arg0, arg1);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_hotControl(IntPtr L)
	{
		try
		{
			LuaDLL.lua_pushinteger(L, UnityEngine.GUIUtility.hotControl);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_keyboardControl(IntPtr L)
	{
		try
		{
			LuaDLL.lua_pushinteger(L, UnityEngine.GUIUtility.keyboardControl);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_systemCopyBuffer(IntPtr L)
	{
		try
		{
			LuaDLL.lua_pushstring(L, UnityEngine.GUIUtility.systemCopyBuffer);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_hasModalWindow(IntPtr L)
	{
		try
		{
			LuaDLL.lua_pushboolean(L, UnityEngine.GUIUtility.hasModalWindow);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_hotControl(IntPtr L)
	{
		try
		{
			int arg0 = (int)LuaDLL.luaL_checknumber(L, 2);
			UnityEngine.GUIUtility.hotControl = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_keyboardControl(IntPtr L)
	{
		try
		{
			int arg0 = (int)LuaDLL.luaL_checknumber(L, 2);
			UnityEngine.GUIUtility.keyboardControl = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_systemCopyBuffer(IntPtr L)
	{
		try
		{
			string arg0 = ToLua.CheckString(L, 2);
			UnityEngine.GUIUtility.systemCopyBuffer = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}
}

