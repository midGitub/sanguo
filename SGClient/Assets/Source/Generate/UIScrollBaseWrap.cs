﻿//this source code was auto-generated by tolua#, do not modify it
using System;
using LuaInterface;

public class UIScrollBaseWrap
{
	public static void Register(LuaState L)
	{
		L.BeginClass(typeof(UIScrollBase), typeof(UnityEngine.EventSystems.UIBehaviour));
		L.RegFunction("OnBeginDrag", OnBeginDrag);
		L.RegFunction("OnDrag", OnDrag);
		L.RegFunction("OnEndDrag", OnEndDrag);
		L.RegFunction("OnInitializePotentialDrag", OnInitializePotentialDrag);
		L.RegFunction("ResetChildren", ResetChildren);
		L.RegFunction("ScrollTo", ScrollTo);
		L.RegFunction("TurnTo", TurnTo);
		L.RegFunction("TurnBy", TurnBy);
		L.RegFunction("__eq", op_Equality);
		L.RegFunction("__tostring", ToLua.op_ToString);
		L.RegVar("controlID", get_controlID, set_controlID);
		L.RegVar("uiMod", get_uiMod, set_uiMod);
		L.RegVar("content", get_content, set_content);
		L.RegVar("viewPort", get_viewPort, set_viewPort);
		L.RegVar("enableDragginEvent", get_enableDragginEvent, set_enableDragginEvent);
		L.RegVar("initOnStart", get_initOnStart, set_initOnStart);
		L.RegVar("moveType", get_moveType, set_moveType);
		L.RegVar("limitExpand", get_limitExpand, set_limitExpand);
		L.RegVar("stopLimit", get_stopLimit, set_stopLimit);
		L.RegVar("monentumEnable", get_monentumEnable, set_monentumEnable);
		L.RegVar("momentumDecay", get_momentumDecay, set_momentumDecay);
		L.RegVar("momentumLimit", get_momentumLimit, set_momentumLimit);
		L.RegVar("momentBoost", get_momentBoost, set_momentBoost);
		L.RegVar("dragInverse", get_dragInverse, set_dragInverse);
		L.RegVar("dragSpeed", get_dragSpeed, set_dragSpeed);
		L.RegVar("dragThreshold", get_dragThreshold, set_dragThreshold);
		L.RegVar("centerOnChild", get_centerOnChild, set_centerOnChild);
		L.RegVar("centerOnChildDecay", get_centerOnChildDecay, set_centerOnChildDecay);
		L.RegVar("centerOnChildFlap", get_centerOnChildFlap, set_centerOnChildFlap);
		L.RegVar("fadeFromCenter", get_fadeFromCenter, set_fadeFromCenter);
		L.RegVar("fadeRatio", get_fadeRatio, set_fadeRatio);
		L.RegVar("scaleFromCenter", get_scaleFromCenter, set_scaleFromCenter);
		L.RegVar("scaleRatio", get_scaleRatio, set_scaleRatio);
		L.RegVar("darkFromCenter", get_darkFromCenter, set_darkFromCenter);
		L.RegVar("darkRatio", get_darkRatio, set_darkRatio);
		L.EndClass();
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int OnBeginDrag(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			UIScrollBase obj = (UIScrollBase)ToLua.CheckObject(L, 1, typeof(UIScrollBase));
			UnityEngine.EventSystems.PointerEventData arg0 = (UnityEngine.EventSystems.PointerEventData)ToLua.CheckObject(L, 2, typeof(UnityEngine.EventSystems.PointerEventData));
			obj.OnBeginDrag(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int OnDrag(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			UIScrollBase obj = (UIScrollBase)ToLua.CheckObject(L, 1, typeof(UIScrollBase));
			UnityEngine.EventSystems.PointerEventData arg0 = (UnityEngine.EventSystems.PointerEventData)ToLua.CheckObject(L, 2, typeof(UnityEngine.EventSystems.PointerEventData));
			obj.OnDrag(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int OnEndDrag(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			UIScrollBase obj = (UIScrollBase)ToLua.CheckObject(L, 1, typeof(UIScrollBase));
			UnityEngine.EventSystems.PointerEventData arg0 = (UnityEngine.EventSystems.PointerEventData)ToLua.CheckObject(L, 2, typeof(UnityEngine.EventSystems.PointerEventData));
			obj.OnEndDrag(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int OnInitializePotentialDrag(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			UIScrollBase obj = (UIScrollBase)ToLua.CheckObject(L, 1, typeof(UIScrollBase));
			UnityEngine.EventSystems.PointerEventData arg0 = (UnityEngine.EventSystems.PointerEventData)ToLua.CheckObject(L, 2, typeof(UnityEngine.EventSystems.PointerEventData));
			obj.OnInitializePotentialDrag(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int ResetChildren(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 1);
			UIScrollBase obj = (UIScrollBase)ToLua.CheckObject(L, 1, typeof(UIScrollBase));
			obj.ResetChildren();
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int ScrollTo(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			UIScrollBase obj = (UIScrollBase)ToLua.CheckObject(L, 1, typeof(UIScrollBase));
			int arg0 = (int)LuaDLL.luaL_checknumber(L, 2);
			obj.ScrollTo(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int TurnTo(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			UIScrollBase obj = (UIScrollBase)ToLua.CheckObject(L, 1, typeof(UIScrollBase));
			int arg0 = (int)LuaDLL.luaL_checknumber(L, 2);
			obj.TurnTo(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int TurnBy(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			UIScrollBase obj = (UIScrollBase)ToLua.CheckObject(L, 1, typeof(UIScrollBase));
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			obj.TurnBy(arg0);
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
	static int get_controlID(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			int ret = obj.controlID;
			LuaDLL.lua_pushinteger(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index controlID on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_uiMod(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			UIMod ret = obj.uiMod;
			ToLua.Push(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index uiMod on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_content(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			UnityEngine.RectTransform ret = obj.content;
			ToLua.Push(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index content on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_viewPort(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			UnityEngine.RectTransform ret = obj.viewPort;
			ToLua.Push(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index viewPort on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_enableDragginEvent(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			bool ret = obj.enableDragginEvent;
			LuaDLL.lua_pushboolean(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index enableDragginEvent on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_initOnStart(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			bool ret = obj.initOnStart;
			LuaDLL.lua_pushboolean(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index initOnStart on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_moveType(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			UIScrollBase.MovementType ret = obj.moveType;
			ToLua.Push(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index moveType on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_limitExpand(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float ret = obj.limitExpand;
			LuaDLL.lua_pushnumber(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index limitExpand on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_stopLimit(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float ret = obj.stopLimit;
			LuaDLL.lua_pushnumber(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index stopLimit on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_monentumEnable(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			bool ret = obj.monentumEnable;
			LuaDLL.lua_pushboolean(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index monentumEnable on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_momentumDecay(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float ret = obj.momentumDecay;
			LuaDLL.lua_pushnumber(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index momentumDecay on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_momentumLimit(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float ret = obj.momentumLimit;
			LuaDLL.lua_pushnumber(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index momentumLimit on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_momentBoost(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float ret = obj.momentBoost;
			LuaDLL.lua_pushnumber(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index momentBoost on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_dragInverse(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			bool ret = obj.dragInverse;
			LuaDLL.lua_pushboolean(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index dragInverse on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_dragSpeed(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float ret = obj.dragSpeed;
			LuaDLL.lua_pushnumber(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index dragSpeed on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_dragThreshold(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float ret = obj.dragThreshold;
			LuaDLL.lua_pushnumber(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index dragThreshold on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_centerOnChild(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			bool ret = obj.centerOnChild;
			LuaDLL.lua_pushboolean(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index centerOnChild on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_centerOnChildDecay(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float ret = obj.centerOnChildDecay;
			LuaDLL.lua_pushnumber(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index centerOnChildDecay on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_centerOnChildFlap(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float ret = obj.centerOnChildFlap;
			LuaDLL.lua_pushnumber(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index centerOnChildFlap on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_fadeFromCenter(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			bool ret = obj.fadeFromCenter;
			LuaDLL.lua_pushboolean(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index fadeFromCenter on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_fadeRatio(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float ret = obj.fadeRatio;
			LuaDLL.lua_pushnumber(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index fadeRatio on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_scaleFromCenter(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			bool ret = obj.scaleFromCenter;
			LuaDLL.lua_pushboolean(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index scaleFromCenter on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_scaleRatio(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float ret = obj.scaleRatio;
			LuaDLL.lua_pushnumber(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index scaleRatio on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_darkFromCenter(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			bool ret = obj.darkFromCenter;
			LuaDLL.lua_pushboolean(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index darkFromCenter on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_darkRatio(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float ret = obj.darkRatio;
			LuaDLL.lua_pushnumber(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index darkRatio on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_controlID(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			int arg0 = (int)LuaDLL.luaL_checknumber(L, 2);
			obj.controlID = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index controlID on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_uiMod(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			UIMod arg0 = (UIMod)ToLua.CheckUnityObject(L, 2, typeof(UIMod));
			obj.uiMod = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index uiMod on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_content(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			UnityEngine.RectTransform arg0 = (UnityEngine.RectTransform)ToLua.CheckUnityObject(L, 2, typeof(UnityEngine.RectTransform));
			obj.content = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index content on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_viewPort(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			UnityEngine.RectTransform arg0 = (UnityEngine.RectTransform)ToLua.CheckUnityObject(L, 2, typeof(UnityEngine.RectTransform));
			obj.viewPort = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index viewPort on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_enableDragginEvent(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			bool arg0 = LuaDLL.luaL_checkboolean(L, 2);
			obj.enableDragginEvent = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index enableDragginEvent on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_initOnStart(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			bool arg0 = LuaDLL.luaL_checkboolean(L, 2);
			obj.initOnStart = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index initOnStart on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_moveType(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			UIScrollBase.MovementType arg0 = (UIScrollBase.MovementType)ToLua.CheckObject(L, 2, typeof(UIScrollBase.MovementType));
			obj.moveType = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index moveType on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_limitExpand(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			obj.limitExpand = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index limitExpand on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_stopLimit(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			obj.stopLimit = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index stopLimit on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_monentumEnable(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			bool arg0 = LuaDLL.luaL_checkboolean(L, 2);
			obj.monentumEnable = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index monentumEnable on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_momentumDecay(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			obj.momentumDecay = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index momentumDecay on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_momentumLimit(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			obj.momentumLimit = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index momentumLimit on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_momentBoost(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			obj.momentBoost = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index momentBoost on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_dragInverse(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			bool arg0 = LuaDLL.luaL_checkboolean(L, 2);
			obj.dragInverse = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index dragInverse on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_dragSpeed(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			obj.dragSpeed = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index dragSpeed on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_dragThreshold(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			obj.dragThreshold = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index dragThreshold on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_centerOnChild(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			bool arg0 = LuaDLL.luaL_checkboolean(L, 2);
			obj.centerOnChild = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index centerOnChild on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_centerOnChildDecay(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			obj.centerOnChildDecay = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index centerOnChildDecay on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_centerOnChildFlap(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			obj.centerOnChildFlap = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index centerOnChildFlap on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_fadeFromCenter(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			bool arg0 = LuaDLL.luaL_checkboolean(L, 2);
			obj.fadeFromCenter = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index fadeFromCenter on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_fadeRatio(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			obj.fadeRatio = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index fadeRatio on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_scaleFromCenter(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			bool arg0 = LuaDLL.luaL_checkboolean(L, 2);
			obj.scaleFromCenter = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index scaleFromCenter on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_scaleRatio(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			obj.scaleRatio = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index scaleRatio on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_darkFromCenter(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			bool arg0 = LuaDLL.luaL_checkboolean(L, 2);
			obj.darkFromCenter = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index darkFromCenter on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_darkRatio(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			UIScrollBase obj = (UIScrollBase)o;
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			obj.darkRatio = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index darkRatio on a nil value" : e.Message);
		}
	}
}

