/*
	NOTE:
	This file was autogenerated by CppGen, changes may be overwritten and forever lost!
	Modify at your own risk!
	
	[ Generated on 2023.03.08 11:30:53 ]
*/

#include "Scripts.hpp"

namespace CppProject
{
	RealType ease_bezier_curve(ArrType p1, ArrType p2, ArrType p3, ArrType p4, RealType t)
	{
		if (t == IntType(0) || t == IntType(1))
			return t;
		RealType lower, upper, perc, xx, xxprev;
		VecType curve;
		lower = IntType(0);
		upper = IntType(1);
		perc = (upper + lower) / 2.0;
		curve = bezier_curve_cubic(p1, p2, p3, p4, perc);
		xx = curve.Real(X_);
		for (IntType i = IntType(0); i < IntType(10) && (abs(t - xx) >= 0.001); i++)
		{
			if (t > xx)
				lower = perc;
			else
				upper = perc;
			
			perc = (upper + lower) / 2.0;
			curve = bezier_curve_cubic(p1, p2, p3, p4, perc);
			xxprev = xx;
			xx = curve.Real(X_);
		}
		curve = bezier_curve_cubic(p1, p2, p3, p4, perc);
		return curve.Real(Y_);
	}
	
	IntType error(StringType name)
	{
		window_set_caption(text_get({ name + /*"caption"*/ STR(26) }));
		show_message(text_get({ name }));
		window_set_caption(/*""*/ STR(0));
		return null_;
	}
	
	VarType eval(VarType str, VarType def)
	{
		IntType i, values, ops;
		VarType result;
		StringType lastoperator;
		values = ds_stack_create();
		ops = ds_stack_create();
		lastoperator = /*""*/ STR(0);
		for (i = IntType(1); i < string_length(str) + IntType(1); i++)
		{
			StringType char_ = string_char_at(str, i);
			if (char_ == /*" "*/ STR(17))
				continue;
			else
				if (char_ == /*"("*/ STR(1069))
				{
					if (lastoperator == /*"--"*/ STR(1070))
						ds_stack_push({ ops, /*"-("*/ STR(1071) });
					else
						ds_stack_push({ ops, /*"("*/ STR(1069) });
					
					lastoperator = /*""*/ STR(0);
				}
				else
					if (eval_is_digit(char_))
					{
						RealType val, dec, decamount;
						BoolType deccheck;
						val = IntType(0);
						dec = IntType(0);
						deccheck = false;
						decamount = IntType(0);
						while (i < (string_length(str) + IntType(1)) && eval_is_digit(string_char_at(str, i)))
						{
							if (string_char_at(str, i) == /*"."*/ STR(1072))
							{
								deccheck = true;
								i++;
								continue;
							}
							if (deccheck)
							{
								dec = (dec * IntType(10)) + real(string_char_at(str, i));
								decamount++;
							}
							else
								val = (val * IntType(10)) + real(string_char_at(str, i));
							
							i++;
						}
						
						i--;
						if (decamount > IntType(0))
							dec /= power(10.0, decamount);
						if (lastoperator == /*"--"*/ STR(1070))
							ds_stack_push({ values, -(val + dec) });
						else
							ds_stack_push({ values, val + dec });
						
						lastoperator = /*""*/ STR(0);
					}
					else
						if (char_ == /*")"*/ STR(1073))
						{
							while (!ds_stack_empty(ops) && !(ds_stack_top(ops) == /*"("*/ STR(1069) || ds_stack_top(ops) == /*"-("*/ STR(1071)))
							{
								VarType val2, val1, op;
								val2 = ds_stack_top(values);
								ds_stack_pop(values);
								val1 = ds_stack_top(values);
								ds_stack_pop(values);
								op = ds_stack_top(ops);
								ds_stack_pop(ops);
								ds_stack_push({ values, eval_solve(val1, val2, op) });
							}
							
							if (!ds_stack_empty(ops))
							{
								if (ds_stack_top(ops) == /*"-("*/ STR(1071))
								{
									VarType val = -ds_stack_top(values);
									ds_stack_pop(values);
									ds_stack_push({ values, val });
								}
								ds_stack_pop(ops);
							}
							lastoperator = /*""*/ STR(0);
						}
						else
						{
							if (lastoperator != /*""*/ STR(0) && char_ == /*"-"*/ STR(1074))
							{
								lastoperator = /*"--"*/ STR(1070);
								continue;
							}
							while (!ds_stack_empty(ops) && eval_precedence(ds_stack_top(ops)) >= eval_precedence(char_))
							{
								VarType val2, val1, op;
								val2 = ds_stack_top(values);
								ds_stack_pop(values);
								val1 = ds_stack_top(values);
								ds_stack_pop(values);
								op = ds_stack_top(ops);
								ds_stack_pop(ops);
								ds_stack_push({ values, eval_solve(val1, val2, op) });
							}
							
							ds_stack_push({ ops, char_ });
							lastoperator = char_;
						}
					
				
			
			
		}
		while (!ds_stack_empty(ops))
		{
			VarType val2, val1, op;
			val2 = ds_stack_top(values);
			ds_stack_pop(values);
			val1 = ds_stack_top(values);
			ds_stack_pop(values);
			op = ds_stack_top(ops);
			ds_stack_pop(ops);
			ds_stack_push({ values, eval_solve(val1, val2, op) });
		}
		
		result = ds_stack_top(values);
		ds_stack_destroy(values);
		ds_stack_destroy(ops);
		if (result == VarType())
			return def;
		else
			return result;
		
		return VarType();
	}
	
	VarType eval_solve(RealType a, RealType b, StringType op)
	{
		if (a == VarType() && b != VarType() && op == /*"-"*/ STR(1074))
			a = IntType(0);
		if (a == VarType() || b == VarType() || op == VarType())
			return VarType();
		switch (StringType(op).id)
		{
			case 1075: // +
			{
				return a + b;
			}
			case 1074: // -
			{
				return a - b;
			}
			case 1076: // *
			{
				return a * b;
			}
			case 16: // /
			{
				return b != IntType(0) ? a / b : 0.0;
			}
			case 1077: // ^
			{
				return power(a, b);
			}
			case 204: // %
			{
				return (mod(a, b));
			}
		}
		
		return VarType();
	}
	
	BoolType eval_is_digit(StringType char_)
	{
		ArrType digits = ArrType::From({ /*"0"*/ STR(1031), /*"1"*/ STR(1078), /*"2"*/ STR(1079), /*"3"*/ STR(1080), /*"4"*/ STR(1081), /*"5"*/ STR(1082), /*"6"*/ STR(1083), /*"7"*/ STR(1084), /*"8"*/ STR(1085), /*"9"*/ STR(1086), /*"."*/ STR(1072) });
		for (IntType i = IntType(0); i < array_length(VarType::CreateRef(digits)); i++)
			if (char_ == digits.Value(i))
				return true;
		return false;
	}
	
	RealType eval_precedence(StringType op)
	{
		switch (StringType(op).id)
		{
			case 1074: // -
			case 1075: // +
			{
				return IntType(1);
			}
			case 16: // /
			case 1076: // *
			case 204: // %
			{
				return IntType(2);
			}
			case 1077: // ^
			{
				return IntType(3);
			}
		}
		
		return IntType(0);
	}
	
	void execute(VarType file, VarType parameters, VarType wait)
	{
		log({ /*"execute"*/ STR(1087), file, parameters, wait });
		lib_execute(file, parameters, wait);
	}
	
	void export_done_image(ScopeAny self)
	{
		render_free();
		surface_free((IntType)(sVar(export_surface)));
		sVar(export_surface) = null_;
		sStr(window_state) = /*""*/ STR(0);
		global::render_watermark = false;
		global::render_background = true;
		global::render_hidden = false;
		toast_new(self, e_toast_POSITIVE, text_get({ /*"alertexportimage"*/ STR(1088) }));
		toast_add_action(self, /*"alertexportimageview"*/ STR(1089), ID_popup_open_url, sStr(export_filename));
	}
	
	void export_done_movie(ScopeAny self, BoolType cancel)
	{
		VarType fn;
		render_free();
		if (sStr(exportmovie_format) != /*"png"*/ STR(60))
		{
			movie_done();
			buffer_delete(sInt(exportmovie_buffer));
		}
		surface_free((IntType)(sVar(export_surface)));
		sVar(export_surface) = null_;
		sStr(window_state) = /*""*/ STR(0);
		global::render_watermark = false;
		global::render_background = true;
		global::render_hidden = false;
		sVar(timeline_marker) = sVar(exportmovie_marker_previous);
		if (sStr(exportmovie_format) == /*"png"*/ STR(60))
			fn = filename_new_ext(sStr(export_filename), /*""*/ STR(0)) + /*"_1.png"*/ STR(1090);
		else
			fn = sStr(export_filename);
		
		if (!cancel)
		{
			toast_new(self, e_toast_POSITIVE, text_get({ /*"alertexportmovie"*/ STR(1091) }));
			toast_add_action(self, /*"alertexportmovieview"*/ STR(1092), ID_popup_open_url, fn);
		}
	}
	
	RealType export_update(ScopeAny self)
	{
		if (keyboard_check(vk_escape) && sInt(export_escape_time) == IntType(0))
			sInt(export_escape_time) = current_time();
		if (sInt(export_escape_time) > IntType(0) && current_time() - sInt(export_escape_time) > IntType(1000))
		{
			sInt(export_escape_time) = IntType(0);
			if (question(text_get({ /*"questionstoprender"*/ STR(1093) })))
			{
				if (sStr(window_state) == /*"export_movie"*/ STR(49))
					export_done_movie(self, true);
				else
					if (sStr(window_state) == /*"export_image"*/ STR(56))
					{
						surface_save_lib(sVar(export_surface), sStr(export_filename));
						export_done_image(self);
					}
				
				return IntType(0);
			}
		}
		if (sStr(window_state) == /*"export_movie"*/ STR(49))
		{
			if (global::render_samples == -IntType(1))
			{
				sVar(timeline_marker) = sVar(exportmovie_marker_start) + (sReal(exportmovie_frame) / ObjType(obj_popup, sInt(popup_exportmovie))->frame_rate) * sVar(project_tempo);
				if (sVar(timeline_marker) > sVar(exportmovie_marker_end))
				{
					export_done_movie(self);
					return IntType(0);
				}
				app_update_animate(self);
			}
		}
		if (sStr(window_state) == /*"export_image"*/ STR(56))
			app_update_cameras(ObjType(obj_popup, sInt(popup_exportimage))->high_quality, false);
		if (sStr(window_state) == /*"export_movie"*/ STR(49))
		{
			global::render_active = /*"movie"*/ STR(1094);
			global::render_quality = ((sReal(exportmovie_high_quality) > 0) ? e_view_mode_RENDER : e_view_mode_SHADED);
		}
		else
		{
			global::render_active = /*"image"*/ STR(90);
			global::render_quality = ((ObjType(obj_popup, sInt(popup_exportimage))->high_quality > 0) ? e_view_mode_RENDER : e_view_mode_SHADED);
		}
		
		if (sStr(window_state) == /*"export_movie"*/ STR(49) && sStr(exportmovie_format) == /*"png"*/ STR(60))
			render_start({ sVar(export_surface), sInt(timeline_camera) });
		else
			render_start({ sVar(export_surface), sInt(timeline_camera), sVar(project_video_width), sVar(project_video_height) });
		
		if (global::render_quality == e_view_mode_RENDER)
			render_high(self);
		else
		{
			render_low(self);
			global::render_samples_done = true;
		}
		
		sVar(export_surface) = render_done();
		sReal(export_sample)++;
		if (global::render_quality == e_view_mode_RENDER && global::render_samples == global::_app->project_render_samples)
			global::render_samples_done = true;
		if (!global::render_samples_done)
			return IntType(1);
		global::render_active = null_;
		global::render_samples = -IntType(1);
		if (sStr(window_state) == /*"export_movie"*/ STR(49))
		{
			if (sStr(exportmovie_format) == /*"png"*/ STR(60))
			{
				RealType totalframes = ceil(((sVar(exportmovie_marker_end) - sVar(exportmovie_marker_start)) / sVar(project_tempo)) * ObjType(obj_popup, sInt(popup_exportmovie))->frame_rate);
				IntType totallen = string_length(string(totalframes));
				StringType numstr = string(sReal(exportmovie_frame) + IntType(1));
				numstr = string_repeat(/*"0"*/ STR(1031), (IntType)((totallen - string_length(numstr)))) + numstr;
				surface_save_lib(sVar(export_surface), filename_new_ext(sStr(export_filename), /*""*/ STR(0)) + /*"_"*/ STR(1095) + numstr + /*".png"*/ STR(6));
			}
			else
			{
				if (!is_cpp())
				{
					buffer_get_surface(sInt(exportmovie_buffer), (IntType)(sVar(export_surface)), IntType(0));
					buffer_save(sInt(exportmovie_buffer), temp_file);
				}
				VarType err = movie_frame(temp_file);
				if (err < IntType(0))
				{
					export_done_movie(self);
					log({ /*"Error when adding frame, error code"*/ STR(1096), err });
					error(/*"errorexportmovie"*/ STR(68));
					return IntType(0);
				}
			}
			
			sReal(exportmovie_frame)++;
			global::current_step += round(60.0 / ObjType(obj_popup, sInt(popup_exportmovie))->frame_rate);
		}
		if (sStr(window_state) == /*"export_image"*/ STR(56))
		{
			surface_save_lib(sVar(export_surface), sStr(export_filename));
			export_done_image(self);
		}
		return IntType(1);
	}
	
	StringType filename_get_unique(StringType fn)
	{
		IntType num;
		StringType newfn, path, ext;
		VarType noext;
		num = IntType(2);
		newfn = fn;
		path = filename_dir(fn) + /*"/"*/ STR(16);
		noext = filename_new_ext(filename_name(fn), /*""*/ STR(0));
		ext = filename_ext(filename_name(fn));
		while (file_exists_lib(newfn))
			newfn = path + noext + /*" ("*/ STR(1097) + string(num++) + /*")"*/ STR(1073) + ext;
		
		return newfn;
	}
	
	VarType filename_get_valid(VarType fn)
	{
		fn = string_replace_all(fn, /*"/"*/ STR(16), /*"_"*/ STR(1095));
		fn = string_replace_all(fn, /*"\\"*/ STR(1098), /*"_"*/ STR(1095));
		fn = string_replace_all(fn, /*":"*/ STR(755), /*"_"*/ STR(1095));
		fn = string_replace_all(fn, /*"*"*/ STR(1076), /*"_"*/ STR(1095));
		fn = string_replace_all(fn, /*"?"*/ STR(1099), /*"_"*/ STR(1095));
		fn = string_replace_all(fn, /*"\""*/ STR(1100), /*"_"*/ STR(1095));
		fn = string_replace_all(fn, /*"<"*/ STR(1101), /*"_"*/ STR(1095));
		fn = string_replace_all(fn, /*">"*/ STR(1102), /*"_"*/ STR(1095));
		fn = string_replace_all(fn, /*"|"*/ STR(851), /*"_"*/ STR(1095));
		while (string_char_at(fn, string_length(fn)) == /*" "*/ STR(17))
			fn = string_copy(fn, IntType(1), (IntType)(string_length(fn) - IntType(1)));
		
		return fn;
	}
	
	VarType filename_new_ext(VarType fn, StringType newext)
	{
		IntType p;
		for (p = string_length(fn); p >= IntType(0); p--)
		{
			StringType c = string_char_at(fn, p);
			if (p == IntType(0) || c == /*"\\"*/ STR(1098) || c == /*"/"*/ STR(16))
				return fn + newext;
			if (c == /*"."*/ STR(1072))
				break;
		}
		return string_copy(fn, IntType(1), (IntType)(p - IntType(1))) + newext;
	}
	
	RealType file_copy_lib(VarType src, VarType dest)
	{
		if (src == dest)
			return IntType(0);
		return lib_file_copy(src, dest);
	}
	
	VarType file_delete_lib(StringType fn)
	{
		return lib_file_delete(fn);
	}
	
	StringType file_dialog_open(VarType filter, StringType filename, StringType directory, VarType title)
	{
		return string(get_open_filename_ext(filter, filename, directory, title));
	}
	
	StringType file_dialog_open_asset()
	{
		return file_dialog_open(text_get({ /*"filedialogopenasset"*/ STR(1103) }) + /*"|"*/ STR(851) + asset_exts, /*""*/ STR(0), /*""*/ STR(0), text_get({ /*"filedialogopenassetcaption"*/ STR(1104) }));
	}
	
	StringType file_dialog_open_font()
	{
		return file_dialog_open(text_get({ /*"filedialogopenfont"*/ STR(1105) }) + /*" (*.ttf)|*.ttf"*/ STR(1106), /*""*/ STR(0), /*""*/ STR(0), text_get({ /*"filedialogopenfontcaption"*/ STR(1107) }));
	}
	
	StringType file_dialog_open_image()
	{
		return file_dialog_open(text_get({ /*"filedialogopenimage"*/ STR(1108) }) + /*" (*.png; *.jpg)|*.png;*.jpg;*.jpeg;"*/ STR(1109), /*""*/ STR(0), /*""*/ STR(0), text_get({ /*"filedialogopenimagecaption"*/ STR(1110) }));
	}
	
	StringType file_dialog_open_image_pack()
	{
		return file_dialog_open(text_get({ /*"filedialogopenimageorpack"*/ STR(1111) }) + /*" (*.png; *.jpg; *.zip)|*.png;*.jpg;*.jpeg;*.zip"*/ STR(1112), /*""*/ STR(0), /*""*/ STR(0), text_get({ /*"filedialogopenimageorpackcaption"*/ STR(1113) }));
	}
	
	StringType file_dialog_open_language()
	{
		return file_dialog_open(text_get({ /*"filedialogopenlanguage"*/ STR(1114) }) + /*" (*.milanguage;*.txt)|*.milanguage;*.txt"*/ STR(1115), /*""*/ STR(0), languages_directory, text_get({ /*"filedialogopenlanguagecaption"*/ STR(1116) }));
	}
	
	StringType file_dialog_open_model()
	{
		return file_dialog_open(text_get({ /*"filedialogopenmodel"*/ STR(1117) }) + /*" (*.mimodel;*.json;*.zip)|*.mimodel;*.json;*.zip"*/ STR(1118), /*""*/ STR(0), /*""*/ STR(0), text_get({ /*"filedialogopenmodelcaption"*/ STR(1119) }));
	}
	
	StringType file_dialog_open_pack()
	{
		return file_dialog_open(text_get({ /*"filedialogopenpack"*/ STR(1120) }) + /*" (*.zip)|*.zip"*/ STR(1121), /*""*/ STR(0), /*""*/ STR(0), text_get({ /*"filedialogopenpackcaption"*/ STR(1122) }));
	}
	
	StringType file_dialog_open_particles()
	{
		return file_dialog_open(text_get({ /*"filedialogopenparticles"*/ STR(1123) }) + /*" (*.miparticles; *.zip; *.particles)|*miparticles;*.zip;*.particles;"*/ STR(1124), /*""*/ STR(0), particles_directory, text_get({ /*"filedialogopenparticlecaption"*/ STR(1125) }));
	}
	
	StringType file_dialog_open_project(ScopeAny self)
	{
		return file_dialog_open(text_get({ /*"filedialogopenproject"*/ STR(1126) }) + /*" (*.miproject; *.zip; *.mproj; *.mani)|*miproject;*.zip;*.mproj;*.mani|"*/ STR(1127) + text_get({ /*"filedialogopenbackup"*/ STR(1128) }) + /*" (*.backup*; *.mbackup*)|*.backup*;*.mbackup*"*/ STR(1129), /*""*/ STR(0), sStr(setting_project_folder), text_get({ /*"filedialogopenprojectcaption"*/ STR(1130) }));
	}
	
	StringType file_dialog_open_render()
	{
		return file_dialog_open(text_get({ /*"filedialogopenrender"*/ STR(1131) }) + /*" (*.mirender)|*mirender"*/ STR(1132), /*""*/ STR(0), /*""*/ STR(0), text_get({ /*"filedialogopenrendercaption"*/ STR(1133) }));
	}
	
	StringType file_dialog_open_scenery()
	{
		return file_dialog_open(text_get({ /*"filedialogopenscenery"*/ STR(1134) }) + /*" (*.schematic; *.nbt; *.blocks)|*.schematic;*.nbt;*.blocks"*/ STR(1135), /*""*/ STR(0), schematics_directory, text_get({ /*"filedialogopenscenerycaption"*/ STR(1136) }));
	}
	
	StringType file_dialog_open_sound()
	{
		return file_dialog_open(text_get({ /*"filedialogopensound"*/ STR(1137) }) + /*" (*.mp3; *.wav; *.ogg; *.flac; *.wma; *.m4a)|*.mp3;*.wav;*.ogg;*.flac;*.wma;*.m4a;"*/ STR(1138), /*""*/ STR(0), /*""*/ STR(0), text_get({ /*"filedialogopensoundcaption"*/ STR(1139) }));
	}
	
	StringType file_dialog_save(VarType filter, VarType filename, StringType directory, VarType title)
	{
		return string(get_save_filename_ext(filter, filename, directory, title));
	}
	
	StringType file_dialog_save_image(VarType fn)
	{
		return file_dialog_save(text_get({ /*"filedialogsaveimage"*/ STR(1140) }) + /*" (*.png)|*.png"*/ STR(1141), filename_get_valid(fn), /*""*/ STR(0), text_get({ /*"filedialogsaveimagecaption"*/ STR(1142) }));
	}
	
	StringType file_dialog_save_keyframes(VarType fn)
	{
		return file_dialog_save(text_get({ /*"filedialogsavekeyframes"*/ STR(1143) }) + /*" (*.miframes)|*.miframes"*/ STR(1144), filename_get_valid(fn), /*""*/ STR(0), text_get({ /*"filedialogsavekeyframescaption"*/ STR(1145) }));
	}
	
	StringType file_dialog_save_movie_mov(ScopeAny self, VarType fn)
	{
		return file_dialog_save(text_get({ /*"filedialogsavemoviemov"*/ STR(1146) }) + /*" (*.mov)|*.mov"*/ STR(1147), filename_get_valid(fn), sStr(project_folder), text_get({ /*"filedialogsavemoviecaption"*/ STR(1148) }));
	}
	
	StringType file_dialog_save_movie_mp4(ScopeAny self, VarType fn)
	{
		return file_dialog_save(text_get({ /*"filedialogsavemoviemp4"*/ STR(1149) }) + /*" (*.mp4)|*.mp4"*/ STR(1150), filename_get_valid(fn), sStr(project_folder), text_get({ /*"filedialogsavemoviecaption"*/ STR(1148) }));
	}
	
	StringType file_dialog_save_movie_png(ScopeAny self, VarType fn)
	{
		return file_dialog_save(text_get({ /*"filedialogsavemoviepng"*/ STR(1151) }) + /*" (*.png)|*.png"*/ STR(1141), filename_get_valid(fn), sStr(project_folder), text_get({ /*"filedialogsavemoviecaption"*/ STR(1148) }));
	}
	
	StringType file_dialog_save_movie_wmv(ScopeAny self, VarType fn)
	{
		return file_dialog_save(text_get({ /*"filedialogsavemoviewmv"*/ STR(1152) }) + /*" (*.wmv)|*.wmv"*/ STR(1153), filename_get_valid(fn), sStr(project_folder), text_get({ /*"filedialogsavemoviecaption"*/ STR(1148) }));
	}
	
	StringType file_dialog_save_object(VarType fn)
	{
		return file_dialog_save(text_get({ /*"filedialogsaveobject"*/ STR(1154) }) + /*" (*.miobject)|*.miobject"*/ STR(1155), filename_get_valid(fn), /*""*/ STR(0), text_get({ /*"filedialogsaveobjectcaption"*/ STR(1156) }));
	}
	
	StringType file_dialog_save_particles(VarType fn)
	{
		return file_dialog_save(text_get({ /*"filedialogsaveparticles"*/ STR(1157) }) + /*" (*.miparticles)|*.miparticles"*/ STR(1158), filename_get_valid(fn), particles_directory, text_get({ /*"filedialogsaveparticlescaption"*/ STR(1159) }));
	}
	
	StringType file_dialog_save_project(ScopeAny self, VarType fn)
	{
		return file_dialog_save(/*""*/ STR(0), fn, sStr(setting_project_folder), text_get({ /*"filedialogsaveprojectcaption"*/ STR(1160) }));
	}
	
	StringType file_dialog_save_render(StringType fn)
	{
		return file_dialog_save(text_get({ /*"filedialogsaverender"*/ STR(1161) }) + /*" (*.mirender)|*.mirender"*/ STR(1162), filename_get_valid(fn), render_directory, text_get({ /*"filedialogsaverendercaption"*/ STR(1163) }));
	}
	
	StringType file_dialog_save_resource(VarType fn, StringType exts)
	{
		return file_dialog_save(/*" * "*/ STR(673) + exts + /*"|*"*/ STR(1164) + exts, filename_get_valid(fn), /*""*/ STR(0), text_get({ /*"filedialogsaveresourcecaption"*/ STR(1165) }));
	}
	
	RealType file_exists_lib(VarType fn)
	{
		if (fn == /*""*/ STR(0))
			return IntType(0);
		return lib_file_exists(fn);
	}
	
	ArrType file_find(StringType dir, StringType exts)
	{
		ArrType ret;
		StringType f;
		ret = ArrType();
		f = file_find_first(dir + /*"*"*/ STR(1076), IntType(0));
		while (f != /*""*/ STR(0))
		{
			if (string_contains(exts, filename_ext(f)))
				ret[array_length(VarType::CreateRef(ret))] = dir + f;
			f = file_find_next();
		}
		
		file_find_close();
		return ret;
	}
	
	StringType file_find_single(StringType dir, StringType exts)
	{
		ArrType ret = file_find(dir, exts);
		if (array_length(VarType::CreateRef(ret)) > IntType(0))
			return ret.Value(IntType(0));
		else
			return /*""*/ STR(0);
		
		return "";
	}
	
	BoolType file_lib_startup()
	{
		log({ /*"working_directory"*/ STR(1166), gmlGlobal::working_directory });
		if (!directory_exists_lib(gmlGlobal::working_directory))
		{
			log({ /*"directory broken"*/ STR(1167) });
			access_error();
			return false;
		}
		IntType surf;
		StringType tmpfile1, tmpfile2;
		surf = surface_create(IntType(32), IntType(32));
		tmpfile1 = file_directory + /*"tmp.png"*/ STR(1168);
		tmpfile2 = data_directory + /*"tmp.png"*/ STR(1168);
		log({ /*"Trying to save files"*/ STR(1169) });
		file_delete_lib(tmpfile1);
		file_delete_lib(tmpfile2);
		surface_save(surf, tmpfile1);
		file_copy_lib(tmpfile1, tmpfile2);
		surface_free(surf);
		if (!file_exists_lib(tmpfile1))
		{
			log({ /*"Couldn't save to file_directory"*/ STR(1170) });
			access_error();
			return false;
		}
		if (!file_exists_lib(tmpfile2))
		{
			log({ /*"Couldn't save to data_directory"*/ STR(1171) });
			access_error();
			return false;
		}
		log({ /*"surface_save OK"*/ STR(1172) });
		IntType tex1, tex2;
		tex1 = texture_create(tmpfile1);
		tex2 = texture_create(tmpfile2);
		if (tex1 < IntType(0) || texture_width(tex1) != IntType(32) || texture_height(tex1) != IntType(32))
		{
			log({ /*"Couldn't load texture from file_directory"*/ STR(1173) });
			access_error();
			return false;
		}
		if (tex2 < IntType(0) || texture_width(tex2) != IntType(32) || texture_height(tex2) != IntType(32))
		{
			log({ /*"Couldn't load texture from data_directory"*/ STR(1174) });
			access_error();
			return false;
		}
		log({ /*"texture_create OK"*/ STR(1175) });
		file_delete_lib(tmpfile1);
		file_delete_lib(tmpfile2);
		if (file_exists_lib(tmpfile1))
		{
			log({ /*"Couldn't delete from file_directory"*/ STR(1176) });
			access_error();
			return false;
		}
		if (file_exists_lib(tmpfile1))
		{
			log({ /*"Couldn't delete from data_directory"*/ STR(1177) });
			access_error();
			return false;
		}
		log({ /*"file_delete_lib OK"*/ STR(1178) });
		return true;
	}
	
	RealType file_rename_lib(VarType oldname, VarType newname)
	{
		if (oldname == /*""*/ STR(0) || oldname == newname)
			return IntType(0);
		return lib_file_rename(oldname, newname);
	}
	
	StringType file_text_contents(StringType fname)
	{
		StringType str;
		IntType line;
		str = /*""*/ STR(0);
		line = IntType(0);
		if (file_exists_lib(fname))
		{
			file_delete_lib(temp_file);
			file_copy_lib(fname, temp_file);
			IntType f = file_text_open_read(temp_file);
			if (f > -IntType(1))
			{
				while (!file_text_eof(f))
				{
					if (line++ > IntType(0))
						str += /*"\n"*/ STR(936);
					str += file_text_read_string(f);
					file_text_readln(f);
				}
				
				file_text_close(f);
			}
		}
		return str;
	}
	
	IntType find_biome(VarType biomename)
	{
		IntType biome = null_;
		for (IntType i = IntType(0); i < IntType(5) && ds_map_exists(global::legacy_biomes_map, biomename); i++)
			biomename = DsMap(global::legacy_biomes_map).Value(biomename);
		withAll (obj_biome, noone)
		{
			if (self->name == biomename)
			{
				biome = self->id;
				break;
			}
		}
		
		return biome;
	}
	
	IntType find_videoquality(RealType bitrate)
	{
		withAll (obj_videoquality, noone)
			if (self->bit_rate == bitrate)
				return self->id;
		
		return null_;
	}
	
	VarType find_videotemplate(VarType w, VarType h)
	{
		withAll (obj_videotemplate, noone)
			if (self->width == w && self->height == h)
				return self->id;
		
		return IntType(0);
	}
	
	IntType font_add_lib(VarArgs argument)
	{
		IntType argument_count = argument.Size();
		StringType tmpfile;
		VarType aa;
		tmpfile = file_directory + /*"tmp.ttf"*/ STR(1179);
		aa = true;
		if (argument_count > IntType(4))
			aa = argument[IntType(4)];
		file_copy_lib(argument[IntType(0)], tmpfile);
		if (file_exists_lib(tmpfile))
		{
			font_add_enable_aa(aa);
			IntType fnt = font_add(tmpfile, (IntType)(argument[IntType(1)]), argument[IntType(2)], argument[IntType(3)], IntType(32), IntType(1024));
			font_add_enable_aa(true);
			if (font_exists(fnt))
				return fnt;
		}
		return null_;
	}
	
	VarType gzunzip(StringType src, StringType dest)
	{
		return lib_gzunzip(src, dest);
	}
	
	RealType halton(RealType i, RealType xx)
	{
		RealType f, r;
		f = IntType(1);
		r = IntType(0);
		while (i > IntType(0))
		{
			f /= xx;
			r = r + f * (mod(i, xx));
			i = floor(i / xx);
		}
		
		return r;
	}
	
	IntType hex_to_color(VarType oldstr)
	{
		StringType str, hex;
		str = string_replace(oldstr, /*"#"*/ STR(827), /*""*/ STR(0));
		str = string_upper(str + string_repeat(/*"0"*/ STR(1031), (IntType)(IntType(6) - string_length(oldstr))));
		hex = /*"0123456789ABCDEF"*/ STR(1006);
		return make_color_rgb((IntType)(string_pos(string_char_at(str, IntType(1)), hex) * IntType(16) + string_pos(string_char_at(str, IntType(2)), hex) - IntType(17)), (IntType)(string_pos(string_char_at(str, IntType(3)), hex) * IntType(16) + string_pos(string_char_at(str, IntType(4)), hex) - IntType(17)), (IntType)(string_pos(string_char_at(str, IntType(5)), hex) * IntType(16) + string_pos(string_char_at(str, IntType(6)), hex) - IntType(17)));
	}
	
	RealType hex_to_dec(StringType hex)
	{
		RealType dec;
		StringType h;
		IntType p;
		hex = string_upper(hex);
		dec = IntType(0);
		h = /*"0123456789ABCDEF"*/ STR(1006);
		for (p = IntType(1); p <= string_length(hex); p++)
			dec = (IntType)dec << (IntType)(IntType)IntType(4) | (IntType)(string_pos(string_char_at(hex, p), h) - IntType(1));
		return dec;
	}
	
	void history_clear(ScopeAny self)
	{
		sReal(history_amount) = IntType(0);
		sReal(history_pos) = IntType(0);
		withAll (obj_history, self->id)
			instance_destroy(ScopeAny(self));
		
		withAll (obj_history_save, self->id)
			instance_destroy(ScopeAny(self));
		
	}
	
	void history_copy_render_settings(ScopeAny self, IntType obj)
	{
		sVar(project_render_samples) = idVar(obj, project_render_samples);
		sVar(project_render_ssao) = idVar(obj, project_render_ssao);
		sVar(project_render_ssao_radius) = idVar(obj, project_render_ssao_radius);
		sVar(project_render_ssao_power) = idVar(obj, project_render_ssao_power);
		sVar(project_render_ssao_color) = idVar(obj, project_render_ssao_color);
		sVar(project_render_shadows) = idVar(obj, project_render_shadows);
		sVar(project_render_shadows_sun_buffer_size) = idVar(obj, project_render_shadows_sun_buffer_size);
		sVar(project_render_shadows_spot_buffer_size) = idVar(obj, project_render_shadows_spot_buffer_size);
		sVar(project_render_shadows_point_buffer_size) = idVar(obj, project_render_shadows_point_buffer_size);
		sVar(project_render_shadows_transparent) = idVar(obj, project_render_shadows_transparent);
		sVar(project_render_subsurface_samples) = idVar(obj, project_render_subsurface_samples);
		sVar(project_render_subsurface_highlight) = idVar(obj, project_render_subsurface_highlight);
		sVar(project_render_subsurface_highlight_strength) = idVar(obj, project_render_subsurface_highlight);
		sVar(project_render_indirect) = idVar(obj, project_render_indirect);
		sVar(project_render_indirect_precision) = idVar(obj, project_render_indirect_precision);
		sVar(project_render_indirect_blur_radius) = idVar(obj, project_render_indirect_blur_radius);
		sVar(project_render_indirect_strength) = idVar(obj, project_render_indirect_strength);
		sVar(project_render_reflections) = idVar(obj, project_render_reflections);
		sVar(project_render_reflections_precision) = idVar(obj, project_render_reflections_precision);
		sVar(project_render_reflections_thickness) = idVar(obj, project_render_reflections_thickness);
		sVar(project_render_reflections_fade_amount) = idVar(obj, project_render_reflections_fade_amount);
		sVar(project_render_glow) = idVar(obj, project_render_glow);
		sVar(project_render_glow_radius) = idVar(obj, project_render_glow_radius);
		sVar(project_render_glow_intensity) = idVar(obj, project_render_glow_intensity);
		sVar(project_render_glow_falloff) = idVar(obj, project_render_glow_falloff);
		sVar(project_render_glow_falloff_radius) = idVar(obj, project_render_glow_falloff_radius);
		sVar(project_render_glow_falloff_intensity) = idVar(obj, project_render_glow_falloff_intensity);
		sVar(project_render_aa) = idVar(obj, project_render_aa);
		sVar(project_render_aa_power) = idVar(obj, project_render_aa_power);
		sVar(project_render_texture_filtering) = idVar(obj, project_render_texture_filtering);
		sVar(project_render_transparent_block_texture_filtering) = idVar(obj, project_render_transparent_block_texture_filtering);
		sVar(project_render_texture_filtering_level) = idVar(obj, project_render_texture_filtering_level);
		sVar(project_bend_style) = idVar(obj, project_bend_style);
		sVar(project_render_opaque_leaves) = idVar(obj, project_render_opaque_leaves);
		sVar(project_render_liquid_animation) = idVar(obj, project_render_liquid_animation);
		sVar(project_render_water_reflections) = idVar(obj, project_render_water_reflections);
		sVar(project_render_block_emissive) = idVar(obj, project_render_block_emissive);
		sVar(project_render_block_subsurface) = idVar(obj, project_render_block_subsurface);
	}
	
	void history_destroy_loaded(Scope<obj_history> self)
	{
		for (IntType i = IntType(0); i < self->loaded_amount; i++)
		{
			withOne (Object, save_id_find(self->loaded_save_id.Value(i)), self->id)
			{
				if (self->subAssetId == ID_obj_resource && sBool(copied))
					file_delete_lib(global::_app->project_folder + /*"/"*/ STR(16) + sVar(filename));
				instance_destroy(self);
			}
			
		}
	}
	
	void history_pop(ScopeAny self)
	{
		sInt(project_changed) = true;
		action_tl_play_break(self);
		if (sReal(history_pos) > IntType(0))
		{
			sReal(history_amount) -= sReal(history_pos);
			for (IntType h = IntType(0); h < sReal(history_amount); h++)
			{
				if (h < sReal(history_pos))
				{
					withOne (obj_history, sArr(history).Value(h), self->id)
					{
						withAll (obj_history_save, self->id)
							if (self->hobj == self.otherId)
								instance_destroy(ScopeAny(self));
						
						instance_destroy(ScopeAny(self));
					}
					
				}
				sArr(history)[h] = sArr(history).Value(h + sReal(history_pos));
			}
		}
		sReal(history_pos) = IntType(0);
		global::render_samples = -IntType(1);
		sBool(history_resource_update) = true;
	}
	
	void history_push(ScopeAny self)
	{
		sReal(history_amount)++;
		for (RealType h = sReal(history_amount); h > IntType(0); h--)
			sArr(history)[h] = sArr(history).Value(h - IntType(1));
	}
	
	IntType history_redo_res(ScopeAny self)
	{
		IntType res;
		if (ObjType(obj_history, global::history_data)->filename != /*""*/ STR(0) && !ObjType(obj_history, global::history_data)->replaced)
		{
			res = new_res(self, ObjType(obj_history, global::history_data)->filename, ObjType(obj_history, global::history_data)->type);
			idVar(res, save_id) = ObjType(obj_history, global::history_data)->new_res_save_id;
			if (ObjType(obj_history, global::history_data)->type == e_res_type_SKIN)
				idVar(res, player_skin) = ObjType(obj_history, global::history_data)->player_skin;
			else
				if (ObjType(obj_history, global::history_data)->type == e_res_type_DOWNLOADED_SKIN)
					idVar(res, player_skin) = true;
				else
					if (ObjType(obj_history, global::history_data)->type == e_res_type_ITEM_SHEET)
						idVar(res, item_sheet_size) = array_copy_1d(ObjType(obj_history, global::history_data)->item_sheet_size);
			
			
			withOne (Object, res, self->id)
				res_load(self);
			
		}
		else
			res = save_id_find(ObjType(obj_history, global::history_data)->new_res_save_id);
		
		return res;
	}
	
	void history_restore_bench(ScopeAny self, IntType save)
	{
		withOne (obj_history_save, save, self->id)
			temp_copy(ScopeAny(self), global::_app->bench_settings);
		
		withOne (obj_bench_settings, sInt(bench_settings), self->id)
		{
			temp_find_save_ids(ScopeAny(self));
			temp_update(ScopeAny(self));
			global::temp_creator = global::_app->bench_settings;
			for (IntType t = IntType(0); t < ObjType(obj_history_save, save)->temp_amount; t++)
			{
				withOne (obj_history_save, ObjType(obj_history_save, save)->temp_save_obj.Value(t), self->id)
				{
					IntType ntemp = (new obj_template)->id;
					temp_copy(ScopeAny(self), ntemp);
					withOne (obj_template, ntemp, self->id)
					{
						self->save_id = ObjType(obj_history_save, self.otherId)->save_id;
						temp_find_save_ids(ScopeAny(self));
						temp_update(ScopeAny(self));
					}
					
				}
				
			}
			global::temp_creator = global::_app->id;
			if (self->type == e_temp_type_PARTICLE_SPAWNER)
			{
				temp_particles_type_clear(ScopeAny(self));
				for (IntType p = IntType(0); p < ObjType(obj_history_save, save)->pc_type_amount; p++)
					history_restore_ptype(ObjType(obj_history_save, save)->pc_type_save_obj.Value(p), self->id);
				temp_particles_restart(ScopeAny(self));
			}
		}
		
	}
	
	void history_restore_keyframes(Scope<obj_history> self)
	{
		for (IntType k = IntType(0); k < self->save_kf_amount; k++)
		{
			withOne (Object, save_id_find(self->save_kf_tl_save_id.Value(k)), self->id)
			{
				VarType kf = tl_keyframe_add(self, { ObjType(obj_history, self.otherId)->save_kf_pos.Value(k) });
				for (IntType v = IntType(0); v < e_value_amount; v++)
					ObjType(obj_keyframe, kf)->value[v] = tl_value_find_save_id(v, ObjType(obj_keyframe, kf)->value.Value(v), ObjType(obj_history, self.otherId)->save_kf_value[k][v]);
			}
			
		}
	}
	
}
