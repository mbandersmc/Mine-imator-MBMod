/*
	NOTE:
	This file was autogenerated by CppGen, changes may be overwritten and forever lost!
	Modify at your own risk!
	
	[ Generated on 2023.03.08 11:30:53 ]
*/

#include "Scripts.hpp"

namespace CppProject
{
	void action_lib_pc_type_spd_mul_israndom(ScopeAny self, VarType israndom)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_spd_mul_israndom, idVar(global::ptype_edit, spd_mul_israndom).Value(global::axis_edit), israndom, false);
		idVar(global::ptype_edit, spd_mul_israndom)[global::axis_edit] = israndom;
	}
	
	void action_lib_pc_type_spd_mul_random_max(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_spd_mul_random_max, idVar(global::ptype_edit, spd_mul_random_max).Value(global::axis_edit), idVar(global::ptype_edit, spd_mul_random_max).Value(global::axis_edit) * add + val, true);
		idVar(global::ptype_edit, spd_mul_random_max)[global::axis_edit] = idVar(global::ptype_edit, spd_mul_random_max).Value(global::axis_edit) * add + val;
	}
	
	void action_lib_pc_type_spd_mul_random_min(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_spd_mul_random_min, idVar(global::ptype_edit, spd_mul_random_min).Value(global::axis_edit), idVar(global::ptype_edit, spd_mul_random_min).Value(global::axis_edit) * add + val, true);
		idVar(global::ptype_edit, spd_mul_random_min)[global::axis_edit] = idVar(global::ptype_edit, spd_mul_random_min).Value(global::axis_edit) * add + val;
	}
	
	void action_lib_pc_type_spd_random_max(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_spd_random_max, idVar(global::ptype_edit, spd_random_max).Value(global::axis_edit), idVar(global::ptype_edit, spd_random_max).Value(global::axis_edit) * add + val, true);
		idVar(global::ptype_edit, spd_random_max)[global::axis_edit] = idVar(global::ptype_edit, spd_random_max).Value(global::axis_edit) * add + val;
	}
	
	void action_lib_pc_type_spd_random_min(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_spd_random_min, idVar(global::ptype_edit, spd_random_min).Value(global::axis_edit), idVar(global::ptype_edit, spd_random_min).Value(global::axis_edit) * add + val, true);
		idVar(global::ptype_edit, spd_random_min)[global::axis_edit] = idVar(global::ptype_edit, spd_random_min).Value(global::axis_edit) * add + val;
	}
	
	void action_lib_pc_type_sprite_angle(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_scale, idVar(global::ptype_edit, sprite_angle), idVar(global::ptype_edit, sprite_angle) * add + val, true);
		idVar(global::ptype_edit, sprite_angle) = idVar(global::ptype_edit, sprite_angle) * add + val;
	}
	
	void action_lib_pc_type_sprite_angle_add(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_scale_add, idVar(global::ptype_edit, sprite_angle_add), idVar(global::ptype_edit, sprite_angle_add) * add + val, true);
		idVar(global::ptype_edit, sprite_angle_add) = idVar(global::ptype_edit, sprite_angle_add) * add + val;
	}
	
	void action_lib_pc_type_sprite_angle_add_israndom(ScopeAny self, VarType israndom)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_angle_add_israndom, idVar(global::ptype_edit, sprite_angle_add_israndom), israndom, false);
		idVar(global::ptype_edit, sprite_angle_add_israndom) = israndom;
	}
	
	void action_lib_pc_type_sprite_angle_add_random_max(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_angle_add_random_max, idVar(global::ptype_edit, sprite_angle_add_random_max), idVar(global::ptype_edit, sprite_angle_add_random_max) * add + val, true);
		idVar(global::ptype_edit, sprite_angle_add_random_max) = idVar(global::ptype_edit, sprite_angle_add_random_max) * add + val;
	}
	
	void action_lib_pc_type_sprite_angle_add_random_min(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_angle_add_random_min, idVar(global::ptype_edit, sprite_angle_add_random_min), idVar(global::ptype_edit, sprite_angle_add_random_min) * add + val, true);
		idVar(global::ptype_edit, sprite_angle_add_random_min) = idVar(global::ptype_edit, sprite_angle_add_random_min) * add + val;
	}
	
	void action_lib_pc_type_sprite_angle_israndom(ScopeAny self, VarType israndom)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_angle_israndom, idVar(global::ptype_edit, sprite_angle_israndom), israndom, false);
		idVar(global::ptype_edit, sprite_angle_israndom) = israndom;
	}
	
	void action_lib_pc_type_sprite_angle_random_max(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_angle_random_max, idVar(global::ptype_edit, sprite_angle_random_max), idVar(global::ptype_edit, sprite_angle_random_max) * add + val, true);
		idVar(global::ptype_edit, sprite_angle_random_max) = idVar(global::ptype_edit, sprite_angle_random_max) * add + val;
	}
	
	void action_lib_pc_type_sprite_angle_random_min(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_angle_random_min, idVar(global::ptype_edit, sprite_angle_random_min), idVar(global::ptype_edit, sprite_angle_random_min) * add + val, true);
		idVar(global::ptype_edit, sprite_angle_random_min) = idVar(global::ptype_edit, sprite_angle_random_min) * add + val;
	}
	
	void action_lib_pc_type_sprite_animation_onend(ScopeAny self, VarType onend)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_animation_onend, idVar(global::ptype_edit, sprite_animation_onend), onend, false);
		idVar(global::ptype_edit, sprite_animation_onend) = onend;
		tab_template_editor_particles_preview_restart(self);
	}
	
	void action_lib_pc_type_sprite_animation_speed(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_animation_speed, idVar(global::ptype_edit, sprite_animation_speed), idVar(global::ptype_edit, sprite_animation_speed) * add + val, true);
		idVar(global::ptype_edit, sprite_animation_speed) = idVar(global::ptype_edit, sprite_animation_speed) * add + val;
		tab_template_editor_particles_preview_restart(self);
	}
	
	void action_lib_pc_type_sprite_animation_speed_israndom(ScopeAny self, VarType israndom)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_animation_speed_israndom, idVar(global::ptype_edit, sprite_animation_speed_israndom), israndom, false);
		idVar(global::ptype_edit, sprite_animation_speed_israndom) = israndom;
		tab_template_editor_particles_preview_restart(self);
	}
	
	void action_lib_pc_type_sprite_animation_speed_random_max(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_animation_speed_random_max, idVar(global::ptype_edit, sprite_animation_speed_random_max), idVar(global::ptype_edit, sprite_animation_speed_random_max) * add + val, true);
		idVar(global::ptype_edit, sprite_animation_speed_random_max) = idVar(global::ptype_edit, sprite_animation_speed_random_max) * add + val;
		tab_template_editor_particles_preview_restart(self);
	}
	
	void action_lib_pc_type_sprite_animation_speed_random_min(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_animation_speed_random_min, idVar(global::ptype_edit, sprite_animation_speed_random_min), idVar(global::ptype_edit, sprite_animation_speed_random_min) * add + val, true);
		idVar(global::ptype_edit, sprite_animation_speed_random_min) = idVar(global::ptype_edit, sprite_animation_speed_random_min) * add + val;
		tab_template_editor_particles_preview_restart(self);
	}
	
	void action_lib_pc_type_sprite_frame_end(ScopeAny self, RealType val, BoolType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_frame_end, idVar(global::ptype_edit, sprite_frame_end), idVar(global::ptype_edit, sprite_frame_end) * (IntType)add + val, true);
		withOne (Object, global::ptype_edit, self->id)
		{
			sVar(sprite_frame_end) = sVar(sprite_frame_end) * (IntType)add + val;
			ptype_update_sprite_vbuffers(self);
		}
		
		tab_template_editor_particles_preview_restart(self);
	}
	
	void action_lib_pc_type_sprite_frame_height(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_frame_height, idVar(global::ptype_edit, sprite_frame_height), idVar(global::ptype_edit, sprite_frame_height) * add + val, true);
		withOne (Object, global::ptype_edit, self->id)
		{
			sVar(sprite_frame_height) = sVar(sprite_frame_height) * add + val;
			ptype_update_sprite_vbuffers(self);
		}
		
		tab_template_editor_particles_preview_restart(self);
	}
	
	void action_lib_pc_type_sprite_frame_start(ScopeAny self, RealType val, BoolType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_frame_start, idVar(global::ptype_edit, sprite_frame_start), idVar(global::ptype_edit, sprite_frame_start) * (IntType)add + val, true);
		withOne (Object, global::ptype_edit, self->id)
		{
			sVar(sprite_frame_start) = sVar(sprite_frame_start) * (IntType)add + val;
			ptype_update_sprite_vbuffers(self);
		}
		
		tab_template_editor_particles_preview_restart(self);
	}
	
	void action_lib_pc_type_sprite_frame_width(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_frame_width, idVar(global::ptype_edit, sprite_frame_width), idVar(global::ptype_edit, sprite_frame_width) * add + val, true);
		withOne (Object, global::ptype_edit, self->id)
		{
			sVar(sprite_frame_width) = sVar(sprite_frame_width) * add + val;
			ptype_update_sprite_vbuffers(self);
		}
		
		tab_template_editor_particles_preview_restart(self);
	}
	
	void action_lib_pc_type_sprite_template(ScopeAny self, VarType temp)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_template, idVar(global::ptype_edit, sprite_template), temp, false);
		idVar(global::ptype_edit, sprite_template) = temp;
		withOne (Object, global::ptype_edit, self->id)
			ptype_update_sprite_vbuffers(self);
		
		tab_template_editor_particles_preview_restart(self);
	}
	
	void action_lib_pc_type_sprite_template_random_frame(ScopeAny self, VarType random_frame)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_template_random_frame, idVar(global::ptype_edit, sprite_template_random_frame), random_frame, true);
		withOne (Object, global::ptype_edit, self->id)
		{
			sVar(sprite_template_random_frame) = random_frame;
			ptype_update_sprite_vbuffers(self);
		}
		
		tab_template_editor_particles_preview_restart(self);
	}
	
	void action_lib_pc_type_sprite_template_reverse(ScopeAny self, VarType reverse)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_template_reverse, idVar(global::ptype_edit, sprite_template_reverse), reverse, true);
		withOne (Object, global::ptype_edit, self->id)
		{
			sVar(sprite_template_reverse) = reverse;
			ptype_update_sprite_vbuffers(self);
		}
		
		tab_template_editor_particles_preview_restart(self);
	}
	
	void action_lib_pc_type_sprite_template_still_frame(ScopeAny self, VarType still_frame)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_template_still_frame, idVar(global::ptype_edit, sprite_template_still_frame), still_frame, true);
		withOne (Object, global::ptype_edit, self->id)
		{
			sVar(sprite_template_still_frame) = still_frame;
			ptype_update_sprite_vbuffers(self);
		}
		
		tab_template_editor_particles_preview_restart(self);
	}
	
	RealType action_lib_pc_type_sprite_template_tex(ScopeAny self, IntType res)
	{
		StringType fn;
		fn = /*""*/ STR(0);
		if (sReal(history_undo) > 0)
			res = history_undo_res();
		else
			if (sReal(history_redo) > 0)
				res = history_redo_res(self);
			else
			{
				if (res == e_option_BROWSE)
				{
					fn = file_dialog_open_pack();
					if (!file_exists_lib(fn))
						return IntType(0);
					res = new_res(self, fn, e_res_type_PACK);
					withOne (Object, res, self->id)
						res_load(self);
					
				}
				history_set_res(self, ID_action_lib_pc_type_sprite_template_tex, fn, idVar(global::ptype_edit, sprite_template_tex), res);
			}
		
		
		withOne (Object, global::ptype_edit, self->id)
		{
			idInt(sVar(sprite_template_tex), count)--;
			sVar(sprite_template_tex) = res;
			idInt(sVar(sprite_template_tex), count)++;
			ptype_update_sprite_vbuffers(self);
		}
		
		tab_template_editor_particles_preview_restart(self);
		return 0.0;
	}
	
	RealType action_lib_pc_type_sprite_tex(ScopeAny self, IntType res)
	{
		StringType fn;
		fn = /*""*/ STR(0);
		if (sReal(history_undo) > 0)
			res = history_undo_res();
		else
			if (sReal(history_redo) > 0)
				res = history_redo_res(self);
			else
			{
				if (res == e_option_BROWSE)
				{
					fn = file_dialog_open_image_pack();
					if (!file_exists_lib(fn))
						return IntType(0);
					res = new_res(self, fn, e_res_type_PARTICLE_SHEET);
					withOne (Object, res, self->id)
						res_load(self);
					
				}
				history_set_res(self, ID_action_lib_pc_type_sprite_tex, fn, idVar(global::ptype_edit, sprite_tex), res);
			}
		
		
		withOne (Object, global::ptype_edit, self->id)
		{
			idInt(sVar(sprite_tex), count)--;
			sVar(sprite_tex) = res;
			idInt(sVar(sprite_tex), count)++;
			ptype_update_sprite_vbuffers(self);
		}
		
		tab_template_editor_particles_preview_restart(self);
		return 0.0;
	}
	
	void action_lib_pc_type_sprite_tex_image(ScopeAny self, VarType image)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_sprite_tex_image, idVar(global::ptype_edit, sprite_tex_image), image, false);
		withOne (Object, global::ptype_edit, self->id)
		{
			sVar(sprite_tex_image) = image;
			ptype_update_sprite_vbuffers(self);
		}
		
		tab_template_editor_particles_preview_restart(self);
	}
	
	void action_lib_pc_type_temp(ScopeAny self, IntType temp)
	{
		if (sReal(history_undo) > 0)
			temp = save_id_find(ObjType(obj_history, global::history_data)->old_value);
		else
			if (sReal(history_redo) > 0)
				temp = save_id_find(ObjType(obj_history, global::history_data)->new_value);
			else
				history_set_var(self, ID_action_lib_pc_type_temp, save_id_get(idVar(global::ptype_edit, temp)), save_id_get(temp), false);
		
		
		idVar(global::ptype_edit, temp) = temp;
		if (temp == particle_sheet || temp == particle_template)
		{
			withOne (Object, global::ptype_edit, self->id)
				ptype_update_sprite_vbuffers(self);
			
		}
		tab_template_editor_particles_preview_restart(self);
	}
	
	void action_lib_pc_type_text(ScopeAny self, VarType text)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_pc_type_text, idVar(global::ptype_edit, text), text, true);
		idVar(global::ptype_edit, text) = text;
	}
	
	void action_lib_remove(ScopeAny self)
	{
		if (sReal(history_undo) > 0)
		{
			withOne (obj_history, global::history_data, self->id)
			{
				global::temp_edit = history_restore_temp(self->temp_save_obj);
				history_restore_tl_select(self);
				for (IntType c = IntType(0); c < self->child_amount; c++)
					withOne (Object, save_id_find(self->child_save_id.Value(c)), self->id)
						tl_set_parent(self, { save_id_find(ObjType(obj_history, self.otherId)->child_parent_save_id.Value(c)), ObjType(obj_history, self.otherId)->child_parent_tree_index.Value(c) });
				
			}
			
		}
		else
		{
			IntType hobj;
			VarType index;
			hobj = null_;
			if (!(sReal(history_redo) > 0))
			{
				hobj = history_set(self, ID_action_lib_remove);
				ObjType(obj_history, hobj)->child_amount = IntType(0);
			}
			withAll (obj_timeline, self->id)
			{
				if (self->temp != global::temp_edit || self->part_list == null_)
					continue;
				IntType index = ds_list_find_index(idInt(self->parent, tree_list), self->id);
				for (IntType t = IntType(0); t < ds_list_size(self->tree_list); t++)
				{
					withOne (obj_timeline, DsList(self->tree_list).Value(t), self->id)
					{
						if (self->part_of != null_)
							continue;
						if (hobj > 0)
						{
							ObjType(obj_history, hobj)->child_save_id[ObjType(obj_history, hobj)->child_amount] = self->save_id;
							ObjType(obj_history, hobj)->child_parent_save_id[ObjType(obj_history, hobj)->child_amount] = idVar(self->parent, save_id);
							ObjType(obj_history, hobj)->child_parent_tree_index[ObjType(obj_history, hobj)->child_amount] = t;
							ObjType(obj_history, hobj)->child_amount++;
						}
						tl_set_parent(ScopeAny(self), { ObjType(obj_timeline, self.otherId)->parent, index });
						t--;
					}
					
				}
				for (IntType p = IntType(0); p < ds_list_size(self->part_list); p++)
				{
					VarType part = DsList(self->part_list).Value(p);
					for (IntType t = IntType(0); t < ds_list_size(idInt(part, tree_list)); t++)
					{
						withOne (obj_timeline, DsList(idInt(part, tree_list)).Value(t), self->id)
						{
							if (self->part_of != null_)
								continue;
							if (hobj > 0)
							{
								ObjType(obj_history, hobj)->child_save_id[ObjType(obj_history, hobj)->child_amount] = self->save_id;
								ObjType(obj_history, hobj)->child_parent_save_id[ObjType(obj_history, hobj)->child_amount] = idVar(self->parent, save_id);
								ObjType(obj_history, hobj)->child_parent_tree_index[ObjType(obj_history, hobj)->child_amount] = t;
								ObjType(obj_history, hobj)->child_amount++;
							}
							tl_set_parent(ScopeAny(self), { ObjType(obj_timeline, self.otherId)->parent, index });
							t--;
						}
						
					}
				}
			}
			
			if (!(sReal(history_redo) > 0))
			{
				withOne (obj_history, hobj, self->id)
				{
					self->temp_save_obj = history_save_temp(ScopeAny(self), global::temp_edit);
					history_save_tl_select(ScopeAny(self));
				}
				
			}
			tl_deselect_all();
			withOne (Object, global::temp_edit, self->id)
				instance_destroy(self);
			
		}
		
		tab_template_editor_update_ptype_list(self);
		sVar(project_ik_part_array) = null_;
		tl_update_length();
		tl_update_list(self);
		tl_update_matrix(self);
		app_update_tl_edit(self);
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	RealType action_lib_scenery(ScopeAny self, IntType res)
	{
		IntType hobj;
		hobj = null_;
		if (sReal(history_undo) > 0)
			res = history_undo_res();
		else
			if (sReal(history_redo) > 0)
				res = history_redo_res(self);
			else
			{
				StringType fn = /*""*/ STR(0);
				res = res;
				if (res == e_option_IMPORT_WORLD)
				{
					world_import_begin(self, false, global::temp_edit);
					return IntType(0);
				}
				else
					if (res == e_option_BROWSE)
					{
						fn = file_dialog_open_scenery();
						if (!file_exists_lib(fn))
							return IntType(0);
						res = new_res(self, fn, e_res_type_SCENERY);
						if (idBool(res, replaced))
						{
							global::res_edit = res;
							action_res_replace(self, { fn });
						}
						else
							withOne (Object, res, self->id)
								res_load(self);
						
						
					}
				
				hobj = history_set_res(self, ID_action_lib_scenery, fn, idVar(global::temp_edit, scenery), res);
				withOne (obj_history, hobj, self->id)
				{
					self->part_amount = IntType(0);
					self->part_child_amount = IntType(0);
					history_save_tl_select(ScopeAny(self));
				}
				
			}
		
		
		tl_deselect_all();
		withOne (Object, global::temp_edit, self->id)
			temp_set_scenery(self, res, !(global::_app->history_undo > 0), hobj);
		
		if (sReal(history_undo) > 0)
			withOne (obj_history, global::history_data, self->id)
				history_restore_parts(self);
		
		tl_update_length();
		tl_update_list(self);
		tl_update_matrix(self);
		app_update_tl_edit(self);
		ObjType(obj_preview, sInt(lib_preview))->update = true;
		return 0.0;
	}
	
	void action_lib_scenery_load(ScopeAny self, VarType fn)
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
				fn = ObjType(obj_history, global::history_data)->filename;
			else
				hobj = history_set(self, ID_action_lib_scenery_load);
			
			IntType res = new_res(self, fn, e_res_type_SCENERY);
			ObjType(obj_resource, res)->loaded = !ObjType(obj_resource, res)->replaced;
			if (ObjType(obj_resource, res)->replaced)
			{
				global::res_edit = res;
				action_res_replace(self, { fn });
			}
			else
				withOne (obj_resource, res, self->id)
					res_load(ScopeAny(self));
			
			
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
				self->filename = fn;
				history_save_loaded(self);
			}
			
		}
		
		project_reset_loaded(self);
		tl_update_list(self);
		tl_update_matrix(self);
	}
	
	void action_lib_shape_closed(ScopeAny self, VarType closed)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_closed, idVar(global::temp_edit, shape_closed), closed, false);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(shape_closed) = closed;
			temp_update_shape(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_shape_detail(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_detail, idVar(global::temp_edit, shape_detail), idVar(global::temp_edit, shape_detail) * add + val, true);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(shape_detail) = sVar(shape_detail) * add + val;
			temp_update_shape(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_shape_face_camera(ScopeAny self, VarType face)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_face_camera, idVar(global::temp_edit, shape_face_camera), face, false);
		idVar(global::temp_edit, shape_face_camera) = face;
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_shape_invert(ScopeAny self, VarType invert)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_invert, idVar(global::temp_edit, shape_invert), invert, false);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(shape_invert) = invert;
			temp_update_shape(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_shape_save_map()
	{
		StringType fn = file_dialog_save_image(DsList(global::temp_type_name_list).Value(idVar(global::temp_edit, type)));
		if (fn != /*""*/ STR(0))
		{
			if (idVar(global::temp_edit, type) == e_temp_type_CONE)
				sprite_save_lib(ID_spr_map_cone, IntType(0), fn);
			else
				if (idVar(global::temp_edit, type) == e_temp_type_CUBE)
					sprite_save_lib(ID_spr_map_cube, IntType(0), fn);
				else
					sprite_save_lib(ID_spr_map_cylinder, IntType(0), fn);
			
			
		}
	}
	
	RealType action_lib_shape_tex(ScopeAny self, IntType res)
	{
		StringType fn;
		fn = /*""*/ STR(0);
		if (sReal(history_undo) > 0)
			res = history_undo_res();
		else
			if (sReal(history_redo) > 0)
				res = history_redo_res(self);
			else
			{
				if (res == e_option_BROWSE)
				{
					fn = file_dialog_open_image();
					if (!file_exists_lib(fn))
						return IntType(0);
					res = new_res(self, fn, e_res_type_TEXTURE);
					withOne (Object, res, self->id)
						res_load(self);
					
				}
				history_set_res(self, ID_action_lib_shape_tex, fn, idVar(global::temp_edit, shape_tex), res);
			}
		
		
		withOne (Object, global::temp_edit, self->id)
		{
			if (sVar(shape_tex) != null_ && idVar(sVar(shape_tex), type) != e_tl_type_CAMERA)
				idInt(sVar(shape_tex), count)--;
			sVar(shape_tex) = res;
			if (sVar(shape_tex) != null_ && idVar(sVar(shape_tex), type) != e_tl_type_CAMERA)
				idInt(sVar(shape_tex), count)++;
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
		return 0.0;
	}
	
	void action_lib_shape_tex_hmirror(ScopeAny self, VarType hmirror)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_tex_hmirror, idVar(global::temp_edit, shape_tex_hmirror), hmirror, false);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(shape_tex_hmirror) = hmirror;
			temp_update_shape(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_shape_tex_hoffset(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_tex_hoffset, idVar(global::temp_edit, shape_tex_hoffset), idVar(global::temp_edit, shape_tex_hoffset) * add + val, true);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(shape_tex_hoffset) = sVar(shape_tex_hoffset) * add + val;
			temp_update_shape(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_shape_tex_hrepeat(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_tex_hrepeat, idVar(global::temp_edit, shape_tex_hrepeat), idVar(global::temp_edit, shape_tex_hrepeat) * add + val, true);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(shape_tex_hrepeat) = sVar(shape_tex_hrepeat) * add + val;
			temp_update_shape(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_shape_tex_mapped(ScopeAny self, VarType map)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_tex_mapped, idVar(global::temp_edit, shape_tex_mapped), map, false);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(shape_tex_mapped) = map;
			temp_update_shape(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	RealType action_lib_shape_tex_material(ScopeAny self, IntType res)
	{
		StringType fn;
		fn = /*""*/ STR(0);
		if (sReal(history_undo) > 0)
			res = history_undo_res();
		else
			if (sReal(history_redo) > 0)
				res = history_redo_res(self);
			else
			{
				if (res == e_option_BROWSE)
				{
					fn = file_dialog_open_image();
					if (!file_exists_lib(fn))
						return IntType(0);
					res = new_res(self, fn, e_res_type_TEXTURE);
					withOne (Object, res, self->id)
						res_load(self);
					
				}
				history_set_res(self, ID_action_lib_shape_tex_material, fn, idVar(global::temp_edit, shape_tex_material), res);
			}
		
		
		withOne (Object, global::temp_edit, self->id)
		{
			if (sVar(shape_tex_material) != null_)
				idInt(sVar(shape_tex_material), count)--;
			sVar(shape_tex_material) = res;
			if (sVar(shape_tex_material) != null_ && idVar(sVar(shape_tex_material), type) != e_tl_type_CAMERA)
				idInt(sVar(shape_tex_material), count)++;
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
		return 0.0;
	}
	
	RealType action_lib_shape_tex_normal(ScopeAny self, IntType res)
	{
		StringType fn;
		fn = /*""*/ STR(0);
		if (sReal(history_undo) > 0)
			res = history_undo_res();
		else
			if (sReal(history_redo) > 0)
				res = history_redo_res(self);
			else
			{
				if (res == e_option_BROWSE)
				{
					fn = file_dialog_open_image();
					if (!file_exists_lib(fn))
						return IntType(0);
					res = new_res(self, fn, e_res_type_TEXTURE);
					withOne (Object, res, self->id)
						res_load(self);
					
				}
				history_set_res(self, ID_action_lib_shape_tex_normal, fn, idVar(global::temp_edit, shape_tex_normal), res);
			}
		
		
		withOne (Object, global::temp_edit, self->id)
		{
			if (sVar(shape_tex_normal) != null_)
				idInt(sVar(shape_tex_normal), count)--;
			sVar(shape_tex_normal) = res;
			if (sVar(shape_tex_normal) != null_ && idVar(sVar(shape_tex_normal), type) != e_tl_type_CAMERA)
				idInt(sVar(shape_tex_normal), count)++;
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
		return 0.0;
	}
	
	void action_lib_shape_tex_vmirror(ScopeAny self, VarType vmirror)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_tex_vmirror, idVar(global::temp_edit, shape_tex_vmirror), vmirror, false);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(shape_tex_vmirror) = vmirror;
			temp_update_shape(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_shape_tex_voffset(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_tex_voffset, idVar(global::temp_edit, shape_tex_voffset), idVar(global::temp_edit, shape_tex_voffset) * add + val, true);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(shape_tex_voffset) = sVar(shape_tex_voffset) * add + val;
			temp_update_shape(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_shape_tex_vrepeat(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_shape_tex_vrepeat, idVar(global::temp_edit, shape_tex_vrepeat), idVar(global::temp_edit, shape_tex_vrepeat) * add + val, true);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(shape_tex_vrepeat) = sVar(shape_tex_vrepeat) * add + val;
			temp_update_shape(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_text_3d(ScopeAny self, VarType is3d)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_text_3d, idVar(global::temp_edit, text_3d), is3d, false);
		withOne (Object, global::temp_edit, self->id)
		{
			sVar(text_3d) = is3d;
			temp_update_rot_point(self);
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	void action_lib_text_face_camera(ScopeAny self, VarType face)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_lib_text_face_camera, idVar(global::temp_edit, text_face_camera), face, false);
		idVar(global::temp_edit, text_face_camera) = face;
		ObjType(obj_preview, sInt(lib_preview))->update = true;
	}
	
	RealType action_lib_text_font(ScopeAny self, IntType res)
	{
		StringType fn;
		fn = /*""*/ STR(0);
		if (sReal(history_undo) > 0)
			res = history_undo_res();
		else
			if (sReal(history_redo) > 0)
				res = history_redo_res(self);
			else
			{
				if (res == e_option_BROWSE)
				{
					fn = file_dialog_open_font();
					if (!file_exists_lib(fn))
						return IntType(0);
					res = new_res(self, fn, e_res_type_FONT);
					withOne (Object, res, self->id)
						res_load(self);
					
				}
				history_set_res(self, ID_action_lib_text_font, fn, idVar(global::temp_edit, text_font), res);
			}
		
		
		withOne (Object, global::temp_edit, self->id)
		{
			if (sVar(text_font) != null_)
				idInt(sVar(text_font), count)--;
			sVar(text_font) = res;
			idInt(sVar(text_font), count)++;
		}
		
		ObjType(obj_preview, sInt(lib_preview))->update = true;
		return 0.0;
	}
	
	void action_project_grid_columns(ScopeAny self, VarType val, VarType add)
	{
		sVar(project_grid_columns) = sVar(project_grid_columns) * add + val;
	}
	
	void action_project_grid_rows(ScopeAny self, VarType val, VarType add)
	{
		sVar(project_grid_rows) = sVar(project_grid_rows) * add + val;
	}
	
	void action_project_render_aa(ScopeAny self, VarType enable)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_aa, sVar(project_render_aa), enable, true);
		sVar(project_render_aa) = enable;
	}
	
	void action_project_render_aa_power(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_aa_power, sVar(project_render_aa_power), sVar(project_render_aa_power) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_aa_power) = sVar(project_render_aa_power) * add + val / 100.0;
	}
	
	void action_project_render_alpha_mode(ScopeAny self, VarType mode)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_alpha_mode, sVar(project_render_alpha_mode), mode, IntType(1));
		sVar(project_render_alpha_mode) = mode;
		global::render_samples = -IntType(1);
	}
	
	void action_project_bend_style(ScopeAny self, VarType style)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_bend_style, sVar(project_bend_style), style, IntType(1));
		sVar(project_bend_style) = style;
		global::render_samples = -IntType(1);
		withAll (obj_timeline, self->id)
		{
			self->bend_rot_last = vec3(IntType(0));
			tl_update_model_shape_bend(ScopeAny(self));
		}
		
	}
	
	void action_project_render_block_emissive(ScopeAny self, RealType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_block_emissive, sVar(project_render_block_emissive), sVar(project_render_block_emissive) * add + val / 100.0, IntType(1));
		else
			val *= 100.0;
		
		sVar(project_render_block_emissive) = sVar(project_render_block_emissive) * add + val / 100.0;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_block_subsurface(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_block_subsurface, sVar(project_render_block_subsurface), sVar(project_render_block_subsurface) * add + val, IntType(1));
		sVar(project_render_block_subsurface) = sVar(project_render_block_subsurface) * add + val;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_distance(ScopeAny self, VarType argument0, VarType argument1)
	{
		sVar(project_render_distance) = sVar(project_render_distance) * argument1 + argument0;
	}
	
	RealType action_project_render_export(ScopeAny self, StringType fn)
	{
		if (fn == /*""*/ STR(0))
			fn = file_dialog_save_render(/*""*/ STR(0));
		if (fn == /*""*/ STR(0))
			return IntType(0);
		project_save_start(fn, false);
		project_save_render(self);
		project_save_done();
		log({ /*"Saved render settings"*/ STR(7), fn });
		toast_new(self, e_toast_POSITIVE, text_get({ /*"alertrendersaved"*/ STR(8) }));
		return 0.0;
	}
	
	void action_project_render_exposure(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_exposure, sVar(project_render_exposure), sVar(project_render_exposure) * add + val, IntType(1));
		sVar(project_render_exposure) = sVar(project_render_exposure) * add + val;
		global::render_samples = -IntType(1);
	}
	
	void action_project_render_gamma(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
			history_set_var(self, ID_action_project_render_gamma, sVar(project_render_gamma), sVar(project_render_gamma) * add + val, IntType(1));
		sVar(project_render_gamma) = sVar(project_render_gamma) * add + val;
		global::render_samples = -IntType(1);
	}
	
}
