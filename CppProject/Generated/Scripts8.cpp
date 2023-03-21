/*
	NOTE:
	This file was autogenerated by CppGen, changes may be overwritten and forever lost!
	Modify at your own risk!
	
	[ Generated on 2023.03.18 17:41:58 ]
*/

#include "Scripts.hpp"

namespace CppProject
{
	void action_res_remove(ScopeAny self)
	{
		IntType hobj = null_;
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				global::res_edit = history_restore_res(self->save_res);
			
		}
		else
			if (!(sReal(history_redo) > 0))
			{
				hobj = history_set(self, ID_action_res_remove);
				withOne (obj_history, hobj, self->id)
				{
					self->save_res = history_save_res(self, global::res_edit);
					self->part_amount = IntType(0);
					self->part_child_amount = IntType(0);
					history_save_tl_select(ScopeAny(self));
				}
				
				tl_deselect_all();
			}
		
		withAll (obj_template, self->id)
		{
			if (self->scenery == global::res_edit)
			{
				if (!(global::_app->history_undo > 0))
					self->scenery = null_;
				temp_set_scenery(ScopeAny(self), self->scenery, !(global::_app->history_undo > 0), hobj);
			}
			else
				if (self->model == global::res_edit)
				{
					if (!(global::_app->history_undo > 0))
						self->model = null_;
					temp_update_model(ScopeAny(self));
					temp_update_model_timeline_tree(ScopeAny(self), hobj);
					temp_update_model_shape(ScopeAny(self));
					temp_update_display_name(ScopeAny(self));
				}
				else
					temp_update(ScopeAny(self));
			
			
			if (self->type == e_temp_type_SPECIAL_BLOCK && idVar(self->model_file, pattern_type) != /*""*/ STR(0))
				array_add(VarType::CreateRef(global::pattern_update), self->id);
		}
		
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_restore_parts(self);
			
		}
		else
			withOne (Object, global::res_edit, self->id)
				instance_destroy(self);
		
		
		sVar(project_ik_part_array) = null_;
		tl_update_length();
		tl_update_list(self);
		tl_update_matrix(self);
		app_update_tl_edit(self);
		ObjType(obj_preview, ObjType(obj_bench_settings, sInt(bench_settings))->preview)->update = true;
		ObjType(obj_preview, sInt(lib_preview))->update = true;
		ObjType(obj_preview, sInt(res_preview))->update = true;
		ObjType(obj_preview, sInt(res_preview))->reset_view = true;
	}
	
	RealType action_res_replace(ScopeAny self, VarArgs argument)
	{
		IntType argument_count = argument.Size();
		IntType hobj = null_;
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
		{
			withOne (Object, global::res_edit, self->id)
			{
				if (argument_count == IntType(0))
					sVar(fn) = res_load_browse(self);
				else
					sVar(fn) = argument[IntType(0)];
				
				if (sVar(fn) == /*""*/ STR(0))
					return IntType(0);
				sVar(scenery_tl_add) = null_;
				sVar(filename) = filename_name(sVar(fn));
				global::load_folder = filename_dir(sVar(fn));
				global::save_folder = global::_app->project_folder;
				if (sVar(type) == e_res_type_DOWNLOADED_SKIN)
					sVar(type) = e_res_type_SKIN;
				res_load(self);
			}
			
			hobj = history_set(self, ID_action_res_replace);
			withOne (obj_history, hobj, self->id)
			{
				self->part_amount = IntType(0);
				self->part_child_amount = IntType(0);
				history_save_tl_select(ScopeAny(self));
			}
			
			tl_deselect_all();
		}
		withAll (obj_template, self->id)
		{
			if (self->scenery == global::res_edit)
				temp_set_scenery(ScopeAny(self), self->scenery, !(global::_app->history_undo > 0), hobj);
			else
				if (self->item_tex == global::res_edit)
					render_generate_item(ScopeAny(self));
				else
					if (self->model == global::res_edit)
					{
						temp_update_model(ScopeAny(self));
						temp_update_model_timeline_tree(ScopeAny(self), hobj);
						temp_update_model_shape(ScopeAny(self));
						temp_update_display_name(ScopeAny(self));
					}
					else
						if (self->model_tex == global::res_edit)
							temp_update_model_shape(ScopeAny(self));
				
			
			
		}
		
		if (sReal(history_undo) > 0)
			withOne (obj_history, global::history_data, self->id)
				history_restore_parts(self);
		
		tl_update_length();
		tl_update_list(self);
		tl_update_matrix(self);
		app_update_tl_edit(self);
		ObjType(obj_preview, sInt(lib_preview))->update = true;
		ObjType(obj_preview, sInt(res_preview))->update = true;
		ObjType(obj_preview, sInt(res_preview))->reset_view = true;
		return 0.0;
	}
	
	void action_res_scenery_animate(ScopeAny self, IntType res)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_destroy_loaded(self);
			
		}
		else
		{
			IntType hobj = null_;
			if (sReal(history_redo) > 0)
				res = save_id_find(ObjType(obj_history, global::history_data)->res);
			else
				hobj = history_set(self, ID_action_res_scenery_animate);
			
			withOne (obj_template, (new obj_template)->id, self->id)
			{
				self->type = e_temp_type_SCENERY;
				self->scenery = res;
				idInt(self->scenery, count)++;
				self->block_tex = global::mc_res;
				self->block_tex_material = global::mc_res;
				self->block_tex_normal = global::mc_res;
				ObjType(obj_resource, global::mc_res)->count += IntType(3);
				temp_update_display_name(ScopeAny(self));
				self->loaded = true;
				withOne (obj_timeline, temp_animate(ScopeAny(self)), self->id)
					self->loaded = true;
				
				sortlist_add(global::_app->lib_list, self->id);
			}
			
			withOne (obj_history, hobj, self->id)
			{
				self->res = save_id_get(res);
				history_save_loaded(self);
			}
			
		}
		
		project_reset_loaded(self);
		tl_update_list(self);
		tl_update_matrix(self);
	}
	
	void action_res_scenery_integrity(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_res_scenery_integrity, idVar(global::res_edit, scenery_integrity), idVar(global::res_edit, scenery_integrity) * add + val / 100.0, true);
		else
			val *= 100.0;
		
		withOne (Object, global::res_edit, self->id)
			sVar(scenery_integrity) = sVar(scenery_integrity) * add + val / 100.0;
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_res_scenery_integrity_invert(ScopeAny self, VarType val)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_res_scenery_integrity_invert, idVar(global::res_edit, scenery_integrity_invert), val, true);
		withOne (Object, global::res_edit, self->id)
		{
			res_load(self, true);
			sVar(scenery_integrity_invert) = val;
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_res_scenery_palette(ScopeAny self, VarType val)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_res_scenery_palette, idVar(global::res_edit, scenery_palette), val, true);
		withOne (Object, global::res_edit, self->id)
			sVar(scenery_palette) = val;
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_res_scenery_randomize(ScopeAny self, VarType val)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_res_scenery_randomize, idVar(global::res_edit, scenery_randomize), val, true);
		withOne (Object, global::res_edit, self->id)
		{
			res_load(self, true);
			sVar(scenery_randomize) = val;
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_res_sound_load(ScopeAny self, VarType fn)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				history_destroy_loaded(self);
			
		}
		else
		{
			IntType res;
			if (sReal(history_redo) > 0)
				fn = ObjType(obj_history, global::history_data)->filename;
			res = new_res(self, fn, e_res_type_SOUND);
			ObjType(obj_resource, res)->loaded = true;
			withOne (obj_resource, res, self->id)
				res_load(ScopeAny(self));
			
			if (!(sReal(history_redo) > 0) && !ObjType(obj_resource, res)->replaced)
			{
				withOne (obj_history, history_set(self, ID_action_res_sound_load), self->id)
				{
					self->filename = fn;
					history_save_loaded(self);
				}
				
			}
		}
		
		project_reset_loaded(self);
	}
	
	void action_setting_accent_custom(ScopeAny self, VarType color)
	{
		sInt(setting_accent) = IntType(9);
		sVar(setting_accent_custom) = color;
		sVar(update_interface_timeout) = current_time() + IntType(10000);
		sBool(update_interface_wait) = true;
	}
	
	void action_setting_backup(ScopeAny self, VarType copy)
	{
		sVar(setting_backup) = copy;
		project_reset_backup(self);
	}
	
	void action_setting_backup_amount(ScopeAny self, VarType val, VarType add)
	{
		sReal(setting_backup_amount) = sReal(setting_backup_amount) * add + val;
	}
	
	void action_setting_backup_time(ScopeAny self, VarType val, VarType add)
	{
		sReal(setting_backup_time) = sReal(setting_backup_time) * add + val;
		project_reset_backup(self);
	}
	
	RealType action_setting_camera_lock_mouse(ScopeAny self, VarType val)
	{
		if (val > 0 && platform_get() == e_platform_MAC_OS && !show_question(text_get({ /*"settingscameralockmousemessage"*/ STR(18) })))
			return IntType(0);
		sVar(setting_camera_lock_mouse) = val;
		window_mouse_set_permission(val);
		if (val > 0)
			display_mouse_set(display_mouse_get_x() + IntType(1), display_mouse_get_y());
		return 0.0;
	}
	
	void action_setting_fade_gizmos(ScopeAny self, VarType yes)
	{
		sVar(setting_fade_gizmos) = yes;
	}
	
	void action_setting_fast_modifier(ScopeAny self, VarType val, VarType add)
	{
		sReal(setting_fast_modifier) = sReal(setting_fast_modifier) * add + val;
	}
	
	void action_setting_gizmos_face_camera(ScopeAny self, VarType yes)
	{
		sVar(setting_gizmos_face_camera) = yes;
	}
	
	RealType action_setting_home_screen(ScopeAny self)
	{
		if (sInt(project_changed) > 0)
		{
			IntType res = show_message_ext(/*"Mine-imator"*/ STR(19), text_get({ /*"questionconfirmopen"*/ STR(20), sVar(project_name) }), text_get({ /*"questionsave"*/ STR(21) }), text_get({ /*"questiondontsave"*/ STR(22) }), text_get({ /*"questioncancel"*/ STR(23) }));
			if (res == IntType(0))
				project_save(self);
			else
				if (res != IntType(1))
					return IntType(0);
			
		}
		log({ /*"Returning to home screen"*/ STR(24) });
		project_reset(self);
		sStr(window_state) = /*"startup"*/ STR(25);
		sVar(window_busy) = /*""*/ STR(0);
		sVar(settings_menu_ani) = IntType(0);
		sStr(settings_menu_ani_type) = /*""*/ STR(0);
		context_menu_close(self);
		popup_close(self);
		return 0.0;
	}
	
	void action_setting_interface_compact(ScopeAny self, VarType enabled)
	{
		sVar(setting_interface_compact) = enabled;
	}
	
	void action_setting_interface_scale(ScopeAny self, VarType argument0)
	{
		sVar(setting_interface_scale) = argument0;
	}
	
	void action_setting_interface_scale_auto(ScopeAny self, VarType enabled)
	{
		sVar(setting_interface_scale_auto) = enabled;
	}
	
	RealType action_setting_language_load(ScopeAny self, StringType fn)
	{
		if (!file_exists_lib(fn))
			return IntType(0);
		sStr(setting_language_filename) = fn;
		language_load(fn, global::language_map);
		withAll (obj_template, self->id)
			temp_update_display_name(ScopeAny(self));
		
		withAll (obj_timeline, self->id)
			tl_update_type_name(ScopeAny(self));
		
		withAll (obj_popup, self->id)
			self->caption = text_get({ self->name + /*"caption"*/ STR(26) });
		
		settings_save(self);
		return 0.0;
	}
	
	void action_setting_look_sensitivity(ScopeAny self, VarType val, VarType add)
	{
		sReal(setting_look_sensitivity) = sReal(setting_look_sensitivity) * add + val;
	}
	
	void action_setting_minecraft_assets_version(ScopeAny self, VarType version)
	{
		if (sStr(setting_minecraft_assets_version) != version)
		{
			sStr(setting_minecraft_assets_version) = version.Str();
			toast_new(self, e_toast_NEGATIVE, text_get({ /*"alertrestartprogram"*/ STR(27) }));
		}
	}
	
	void action_setting_move_speed(ScopeAny self, VarType val, VarType add)
	{
		sReal(setting_move_speed) = sReal(setting_move_speed) * add + val;
	}
	
	RealType action_setting_program_mode(ScopeAny self, BoolType advanced)
	{
		if (advanced && global::trial_version > 0)
		{
			popup_show(self, sInt(popup_upgrade));
			ObjType(obj_popup, sInt(popup_upgrade))->page = IntType(1);
			ObjType(obj_popup, sInt(popup_upgrade))->open_advanced = true;
			return IntType(0);
		}
		sReal(setting_advanced_mode) = advanced;
		return 0.0;
	}
	
	void action_setting_project_folder(ScopeAny self, StringType directory)
	{
		sStr(setting_project_folder) = directory;
	}
	
	void action_setting_reduced_motion(ScopeAny self, VarType enabled)
	{
		sVar(setting_reduced_motion) = enabled;
	}
	
	void action_setting_scenery_remove_edges(ScopeAny self, VarType val)
	{
		sVar(setting_scenery_remove_edges) = val;
		toast_new(self, e_toast_WARNING, text_get({ /*"alertreloadobjects"*/ STR(11) }));
	}
	
	void action_setting_search_variants(ScopeAny self, VarType yes)
	{
		sVar(setting_search_variants) = yes;
	}
	
	void action_setting_secondary_view(ScopeAny self)
	{
		ObjType(obj_view, sInt(view_second))->show = !(ObjType(obj_view, sInt(view_second))->show > 0);
		if (!(ObjType(obj_view, sInt(view_second))->show > 0))
			window_close(e_window_VIEW_SECOND);
		else
			ObjType(obj_view, sInt(view_second))->location = ObjType(obj_view, sInt(view_second))->location_last;
		
	}
	
	void action_setting_separate_tool_modes(ScopeAny self, VarType yes)
	{
		sVar(setting_separate_tool_modes) = yes;
		action_tools_disable_all(self);
		sBool(setting_tool_select) = sVar(setting_separate_tool_modes);
	}
	
	void action_setting_shortcuts_bar(ScopeAny self)
	{
		sBool(setting_show_shortcuts_bar) = !sBool(setting_show_shortcuts_bar);
	}
	
	void action_setting_slow_modifier(ScopeAny self, VarType val, VarType add)
	{
		sReal(setting_slow_modifier) = sReal(setting_slow_modifier) * add + val;
	}
	
	void action_setting_snap_absolute(ScopeAny self, VarType absolute)
	{
		sVar(setting_snap_absolute) = absolute;
	}
	
	void action_setting_snap_size_position(ScopeAny self, VarType val, VarType add)
	{
		sReal(setting_snap_size_position) = sReal(setting_snap_size_position) * add + val;
	}
	
	void action_setting_snap_size_rotation(ScopeAny self, VarType val, VarType add)
	{
		sReal(setting_snap_size_rotation) = sReal(setting_snap_size_rotation) * add + val;
	}
	
	void action_setting_snap_size_scale(ScopeAny self, VarType val, VarType add)
	{
		sReal(setting_snap_size_scale) = sReal(setting_snap_size_scale) * add + val;
	}
	
	void action_setting_spawn_cameras(ScopeAny self, VarType spawn)
	{
		sVar(setting_spawn_cameras) = spawn;
	}
	
	void action_setting_theme(ScopeAny self, VarType theme)
	{
		sInt(setting_theme) = theme;
		sVar(update_interface_timeout) = current_time() + IntType(10000);
		sBool(update_interface_wait) = true;
	}
	
	void action_setting_timeline_autoscroll(ScopeAny self, VarType autoscroll)
	{
		sVar(setting_timeline_autoscroll) = autoscroll;
	}
	
	void action_setting_timeline_compact(ScopeAny self)
	{
		sReal(setting_timeline_compact) = !(sReal(setting_timeline_compact) > 0);
	}
	
	void action_setting_timeline_display_frames(ScopeAny self)
	{
		sReal(timeline_show_frames) = true;
	}
	
	void action_setting_timeline_display_time(ScopeAny self)
	{
		sReal(timeline_show_frames) = false;
	}
	
	void action_setting_timeline_frame_snap(ScopeAny self, VarType enable)
	{
		sVar(setting_timeline_frame_snap) = enable;
	}
	
	void action_setting_timeline_hide_ghosts(ScopeAny self, VarType hide)
	{
		sVar(setting_timeline_hide_ghosts) = hide;
		tl_update_list(self);
	}
	
	void action_setting_timeline_select_jump(ScopeAny self, VarType jump)
	{
		sVar(setting_timeline_select_jump) = jump;
	}
	
	void action_setting_timeline_show_markers(ScopeAny self)
	{
		sBool(setting_timeline_show_markers) = !sBool(setting_timeline_show_markers);
	}
	
	RealType action_setting_unlimited_values(ScopeAny self, VarType unlimited_values)
	{
		if (unlimited_values > 0)
		{
			if (!question(text_get({ /*"questionunlimitedvalues"*/ STR(28) })))
				return IntType(0);
		}
		sReal(setting_unlimited_values) = unlimited_values;
		return 0.0;
	}
	
	RealType action_setting_watermark_custom(ScopeAny self, VarType custom)
	{
		if (global::trial_version > 0)
		{
			popup_show(self, sInt(popup_upgrade));
			ObjType(obj_popup, sInt(popup_upgrade))->page = IntType(0);
			return IntType(0);
		}
		sVar(setting_watermark_custom) = custom;
		return 0.0;
	}
	
	void action_setting_watermark_halign(ScopeAny self, VarType halign)
	{
		sVar(setting_watermark_halign) = halign;
	}
	
	RealType action_setting_watermark_import(ScopeAny self)
	{
		StringType fn = file_dialog_open_image();
		if (fn == /*""*/ STR(0))
			return IntType(0);
		sStr(setting_watermark_fn) = data_directory + /*"watermark"*/ STR(29) + filename_ext(fn);
		file_copy_lib(fn, sStr(setting_watermark_fn));
		sInt(setting_watermark_image) = texture_create(sStr(setting_watermark_fn));
		return 0.0;
	}
	
	void action_setting_watermark_opacity(ScopeAny self, RealType val, VarType add)
	{
		sReal(setting_watermark_opacity) = sReal(setting_watermark_opacity) * add + val / 100.0;
	}
	
	void action_setting_watermark_padding(ScopeAny self, RealType val, VarType add)
	{
		sReal(setting_watermark_padding) = sReal(setting_watermark_padding) * add + val / 100.0;
	}
	
	void action_setting_watermark_reset(ScopeAny self)
	{
		file_delete_lib(sStr(setting_watermark_fn));
		sStr(setting_watermark_fn) = /*""*/ STR(0);
		sprite_delete(sInt(setting_watermark_image));
		sInt(setting_watermark_image) = null_;
	}
	
	void action_setting_watermark_scale(ScopeAny self, RealType val, VarType add)
	{
		sReal(setting_watermark_scale) = sReal(setting_watermark_scale) * add + val / 100.0;
	}
	
	void action_setting_watermark_valign(ScopeAny self, VarType valign)
	{
		sVar(setting_watermark_valign) = valign;
	}
	
	void action_setting_z_is_up(ScopeAny self, VarType yes)
	{
		sReal(setting_z_is_up) = yes;
	}
	
	void action_textbox_copy(ScopeAny self)
	{
		sBool(context_menu_tbx_action) = true;
		sBool(context_menu_tbx_copy) = true;
	}
	
	void action_textbox_cut(ScopeAny self)
	{
		sBool(context_menu_tbx_action) = true;
		sBool(context_menu_tbx_cut) = true;
	}
	
	void action_textbox_paste(ScopeAny self)
	{
		sBool(context_menu_tbx_action) = true;
		sBool(context_menu_tbx_paste) = true;
	}
	
	void action_textbox_select_all(ScopeAny self)
	{
		sBool(context_menu_tbx_action) = true;
		sBool(context_menu_tbx_select_all) = true;
	}
	
	RealType action_tl_add_sound(ScopeAny self)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (Object, global::tl_edit, self->id)
			{
				withOne (obj_keyframe, DsList(sInt(keyframe_list)).Value(ObjType(obj_history, global::history_data)->kf_index), self->id)
					instance_destroy(ScopeAny(self));
				
				tl_update_values(self);
			}
			
			withOne (obj_history, global::history_data, self->id)
				history_destroy_loaded(self);
			
		}
		else
		{
			VarType fn, pos;
			IntType res, kf, hobj;
			if (sReal(history_redo) > 0)
			{
				fn = ObjType(obj_history, global::history_data)->filename;
				pos = ObjType(obj_history, global::history_data)->position;
			}
			else
			{
				fn = file_dialog_open_sound();
				if (!file_exists_lib(fn))
					return IntType(0);
				pos = sVar(timeline_marker);
				hobj = history_set(self, ID_action_tl_add_sound);
			}
			
			res = new_res(self, fn, e_res_type_SOUND);
			ObjType(obj_resource, res)->loaded = !ObjType(obj_resource, res)->replaced;
			withOne (obj_resource, res, self->id)
				res_load(ScopeAny(self));
			
			withOne (Object, global::tl_edit, self->id)
			{
				kf = tl_keyframe_add(self, pos);
				ObjType(obj_keyframe, kf)->value[e_value_SOUND_OBJ] = res;
				ObjType(obj_resource, res)->count++;
				tl_update_values(self);
			}
			
			if (!(sReal(history_redo) > 0))
			{
				withOne (obj_history, hobj, self->id)
				{
					self->filename = fn;
					self->position = pos;
					self->kf_index = ds_list_find_index(idInt(global::tl_edit, keyframe_list), kf);
					history_save_loaded(self);
				}
				
			}
		}
		
		project_reset_loaded(self);
		tl_update_length();
		return 0.0;
	}
	
	void action_tl_alpha_mode(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(alpha_mode) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(alpha_mode) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_alpha_mode, false);
				withAll (obj_timeline, self->id)
					if (self->selected > 0)
						action_tl_alpha_mode_tree(self->id, enable, hobj);
				
			}
		
		
	}
	
	void action_tl_alpha_mode_tree(VarType tl, VarType nval, VarType hobj)
	{
		withOne (obj_history, hobj, noone)
			history_save_var(self, tl, ObjType(obj_timeline, tl)->alpha_mode, nval);
		
		ObjType(obj_timeline, tl)->alpha_mode = nval;
		for (IntType i = IntType(0); i < ds_list_size(ObjType(obj_timeline, tl)->tree_list); i++)
			if (!(ObjType(obj_timeline, DsList(ObjType(obj_timeline, tl)->tree_list).Value(i))->selected > 0))
				action_tl_alpha_mode_tree(DsList(ObjType(obj_timeline, tl)->tree_list).Value(i), nval, hobj);
	}
	
	void action_tl_backfaces(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(backfaces) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(backfaces) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_backfaces, false);
				withAll (obj_timeline, self->id)
					if (self->selected > 0)
						action_tl_backfaces_tree(self->id, enable, hobj);
				
			}
		
		
	}
	
	void action_tl_backfaces_tree(VarType tl, VarType nval, VarType hobj)
	{
		withOne (obj_history, hobj, noone)
			history_save_var(self, tl, ObjType(obj_timeline, tl)->backfaces, nval);
		
		ObjType(obj_timeline, tl)->backfaces = nval;
		for (IntType i = IntType(0); i < ds_list_size(ObjType(obj_timeline, tl)->tree_list); i++)
			if (!(ObjType(obj_timeline, DsList(ObjType(obj_timeline, tl)->tree_list).Value(i))->selected > 0))
				action_tl_backfaces_tree(DsList(ObjType(obj_timeline, tl)->tree_list).Value(i), nval, hobj);
	}
	
	void action_tl_blend_mode(ScopeAny self, VarType enable)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(blend_mode) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(blend_mode) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_blend_mode, false);
				withAll (obj_timeline, self->id)
					if (self->selected > 0)
						action_tl_blend_mode_tree(self->id, enable, hobj);
				
			}
		
		
	}
	
	void action_tl_blend_mode_tree(VarType tl, VarType nval, VarType hobj)
	{
		withOne (obj_history, hobj, noone)
			history_save_var(self, tl, ObjType(obj_timeline, tl)->blend_mode, nval);
		
		ObjType(obj_timeline, tl)->blend_mode = nval;
		for (IntType i = IntType(0); i < ds_list_size(ObjType(obj_timeline, tl)->tree_list); i++)
			if (!(ObjType(obj_timeline, DsList(ObjType(obj_timeline, tl)->tree_list).Value(i))->selected > 0))
				action_tl_blend_mode_tree(DsList(ObjType(obj_timeline, tl)->tree_list).Value(i), nval, hobj);
	}
	
	void action_tl_collapse_all(ScopeAny self)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(tree_extend) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(tree_extend) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_collapse_all, false);
				for (IntType t = IntType(0); t < ds_list_size(sInt(tree_list)); t++)
					withOne (obj_timeline, DsList(sInt(tree_list)).Value(t), self->id)
						action_tl_extend_children_tree(self->id, false, hobj);
				
			}
		
		
		tl_update_list(self);
	}
	
	void action_tl_collapse_children(ScopeAny self)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(tree_extend) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
			
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(tree_extend) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
				
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_collapse_children, false);
				action_tl_extend_children_tree(global::list_item_value, false, hobj);
			}
		
		
		tl_update_list(self);
	}
	
	void action_tl_color_tag(ScopeAny self, IntType color)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
			{
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
				{
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						sVar(color_tag) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
					
				}
			}
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
				{
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
					{
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
							sVar(color_tag) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
						
					}
				}
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_color_tag, false);
				if (global::list_item_value == null_ || idReal(global::list_item_value, selected) > 0)
				{
					withAll (obj_timeline, self->id)
					{
						if (!(self->selected > 0))
							continue;
						withOne (obj_history, hobj, self->id)
							history_save_var(self, self.otherId, ObjType(obj_timeline, self.otherId)->color_tag, color);
						
						self->color_tag = color;
					}
					
				}
				else
				{
					withOne (Object, global::list_item_value, self->id)
					{
						withOne (obj_history, hobj, self->id)
							history_save_var(self, self.otherId, idVar(self.otherId, color_tag), color);
						
						sVar(color_tag) = color;
					}
					
				}
				
			}
		
		
	}
	
	void action_tl_color_tag_remove(ScopeAny self)
	{
		action_tl_color_tag(self, null_);
	}
	
	void action_tl_depth(ScopeAny self, VarType val, VarType add)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
			{
				for (IntType t = IntType(0); t < self->save_var_amount; t++)
				{
					withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
					{
						sVar(depth) = ObjType(obj_history, self.otherId)->save_var_old_value.Value(t);
						tl_update_depth(self);
					}
					
				}
			}
			
		}
		else
			if (sReal(history_redo) > 0)
			{
				withOne (obj_history, global::history_data, self->id)
				{
					for (IntType t = IntType(0); t < self->save_var_amount; t++)
					{
						withOne (Object, save_id_find(self->save_var_save_id.Value(t)), self->id)
						{
							sVar(depth) = ObjType(obj_history, self.otherId)->save_var_new_value.Value(t);
							tl_update_depth(self);
						}
						
					}
				}
				
			}
			else
			{
				VarType hobj = history_save_var_start(self, ID_action_tl_depth, true);
				withAll (obj_timeline, self->id)
					if (self->selected > 0)
						action_tl_depth_tree(self->id, val, add, hobj);
				
			}
		
		
	}
	
}
