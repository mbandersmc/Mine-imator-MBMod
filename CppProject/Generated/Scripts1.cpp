/*
	NOTE:
	This file was autogenerated by CppGen, changes may be overwritten and forever lost!
	Modify at your own risk!
	
	[ Generated on 2023.03.18 17:41:58 ]
*/

#include "Scripts.hpp"

namespace CppProject
{
	app::app()
		: Object("app", ID_app)
	{
		InitMembers();
		global::_app = this;
	}
	
	obj_bench_settings::obj_bench_settings()
		: Object("obj_bench_settings", ID_obj_bench_settings)
	{
		InitMembers();
	}
	
	obj_biome::obj_biome()
		: Object("obj_biome", ID_obj_biome)
	{
		InitMembers();
	}
	
	obj_block::obj_block()
		: Object("obj_block", ID_obj_block)
	{
		InitMembers();
	}
	
	obj_block_load_element::obj_block_load_element()
		: Object("obj_block_load_element", ID_obj_block_load_element)
	{
		InitMembers();
	}
	
	obj_block_load_model_file::obj_block_load_model_file()
		: Object("obj_block_load_model_file", ID_obj_block_load_model_file)
	{
		InitMembers();
	}
	
	obj_block_load_model_file::~obj_block_load_model_file()
	{
		block_load_model_file_event_destroy(Scope<obj_block_load_model_file>(this));
	}
	
	obj_block_load_multipart_case::obj_block_load_multipart_case()
		: Object("obj_block_load_multipart_case", ID_obj_block_load_multipart_case)
	{
		InitMembers();
	}
	
	obj_block_load_state_file::obj_block_load_state_file()
		: Object("obj_block_load_state_file", ID_obj_block_load_state_file)
	{
		InitMembers();
	}
	
	obj_block_load_variant::obj_block_load_variant()
		: Object("obj_block_load_variant", ID_obj_block_load_variant)
	{
		InitMembers();
	}
	
	obj_block_render_element::obj_block_render_element()
		: Object("obj_block_render_element", ID_obj_block_render_element)
	{
		InitMembers();
	}
	
	obj_block_render_model::obj_block_render_model()
		: Object("obj_block_render_model", ID_obj_block_render_model)
	{
		InitMembers();
	}
	
	obj_block_state::obj_block_state()
		: Object("obj_block_state", ID_obj_block_state)
	{
		InitMembers();
	}
	
	obj_block_tl::obj_block_tl()
		: Object("obj_block_tl", ID_obj_block_tl)
	{
		InitMembers();
	}
	
	obj_block_tl_state::obj_block_tl_state()
		: Object("obj_block_tl_state", ID_obj_block_tl_state)
	{
		InitMembers();
	}
	
	obj_builder::obj_builder()
		: Object("obj_builder", ID_obj_builder)
	{
		InitMembers();
		builder_event_create(Scope<obj_builder>(this));
	}
	
	obj_builder_thread::obj_builder_thread()
		: Object("obj_builder_thread", ID_obj_builder_thread)
	{
		InitMembers();
		builder_thread_event_create(Scope<obj_builder_thread>(this));
	}
	
	obj_category::obj_category()
		: Object("obj_category", ID_obj_category)
	{
		InitMembers();
	}
	
	obj_colorpicker::obj_colorpicker()
		: Object("obj_colorpicker", ID_obj_colorpicker)
	{
		InitMembers();
	}
	
	obj_context_menu_level::obj_context_menu_level()
		: Object("obj_context_menu_level", ID_obj_context_menu_level)
	{
		InitMembers();
	}
	
	obj_data::obj_data()
		: Object("obj_data", ID_obj_data)
	{
		InitMembers();
	}
	
	obj_deactivate::obj_deactivate()
		: Object("obj_deactivate", ID_obj_deactivate)
	{
		InitMembers();
	}
	
	obj_history::obj_history()
		: Object("obj_history", ID_obj_history)
	{
		InitMembers();
	}
	
	obj_history_save::obj_history_save()
		: Object("obj_history_save", ID_obj_history_save)
	{
		InitMembers();
	}
	
	obj_keybind::obj_keybind()
		: Object("obj_keybind", ID_obj_keybind)
	{
		InitMembers();
		keybind_event_create(Scope<obj_keybind>(this));
	}
	
	obj_keyframe::obj_keyframe()
		: Object("obj_keyframe", ID_obj_keyframe)
	{
		InitMembers();
	}
	
	obj_keyframe::~obj_keyframe()
	{
		keyframe_event_destroy(Scope<obj_keyframe>(this));
	}
	
	obj_language::obj_language()
		: Object("obj_language", ID_obj_language)
	{
		InitMembers();
	}
	
	obj_list::obj_list()
		: Object("obj_list", ID_obj_list)
	{
		InitMembers();
	}
	
	obj_list::~obj_list()
	{
		list_event_destroy(Scope<obj_list>(this));
	}
	
	obj_list_item::obj_list_item()
		: Object("obj_list_item", ID_obj_list_item)
	{
		InitMembers();
	}
	
	obj_list_item::~obj_list_item()
	{
		list_item_event_destroy(Scope<obj_list_item>(this));
	}
	
	obj_marker::obj_marker()
		: Object("obj_marker", ID_obj_marker)
	{
		InitMembers();
		marker_event_create(Scope<obj_marker>(this));
	}
	
	obj_marker::~obj_marker()
	{
		marker_event_destroy(Scope<obj_marker>(this));
	}
	
	obj_menu::obj_menu()
		: Object("obj_menu", ID_obj_menu)
	{
		InitMembers();
		menu_event_create(Scope<obj_menu>(this));
	}
	
	obj_menu::~obj_menu()
	{
		menu_event_destroy(ScopeAny(this->id));
	}
	
	obj_micro_animation::obj_micro_animation()
		: Object("obj_micro_animation", ID_obj_micro_animation)
	{
		InitMembers();
	}
	
	obj_minecraft_assets::obj_minecraft_assets()
		: Object("obj_minecraft_assets", ID_obj_minecraft_assets)
	{
		InitMembers();
		minecraft_assets_event_create(Scope<obj_minecraft_assets>(this));
	}
	
	obj_model::obj_model()
		: Object("obj_model", ID_obj_model)
	{
		InitMembers();
	}
	
	obj_model_file::obj_model_file()
		: Object("obj_model_file", ID_obj_model_file)
	{
		InitMembers();
	}
	
	obj_model_file::~obj_model_file()
	{
		model_file_event_destroy(Scope<obj_model_file>(this));
	}
	
	obj_model_part::obj_model_part()
		: Object("obj_model_part", ID_obj_model_part)
	{
		InitMembers();
	}
	
	obj_model_part::~obj_model_part()
	{
		model_part_event_destroy(Scope<obj_model_part>(this));
	}
	
	obj_model_shape::obj_model_shape()
		: Object("obj_model_shape", ID_obj_model_shape)
	{
		InitMembers();
	}
	
	obj_model_shape::~obj_model_shape()
	{
		model_shape_event_destroy(Scope<obj_model_shape>(this));
	}
	
	obj_model_state::obj_model_state()
		: Object("obj_model_state", ID_obj_model_state)
	{
		InitMembers();
	}
	
	obj_panel::obj_panel()
		: Object("obj_panel", ID_obj_panel)
	{
		InitMembers();
		panel_event_create(Scope<obj_panel>(this));
	}
	
	obj_particle::obj_particle()
		: Object("obj_particle", ID_obj_particle)
	{
		InitMembers();
	}
	
	obj_particle::~obj_particle()
	{
		particle_event_destroy(Scope<obj_particle>(this));
	}
	
	obj_particle_template::obj_particle_template()
		: Object("obj_particle_template", ID_obj_particle_template)
	{
		InitMembers();
	}
	
	obj_particle_type::obj_particle_type()
		: Object("obj_particle_type", ID_obj_particle_type)
	{
		InitMembers();
		ptype_event_create(Scope<obj_particle_type>(this));
	}
	
	obj_particle_type::~obj_particle_type()
	{
		ptype_event_destroy(Scope<obj_particle_type>(this));
	}
	
	obj_popup::obj_popup()
		: Object("obj_popup", ID_obj_popup)
	{
		InitMembers();
	}
	
	obj_preview::obj_preview()
		: Object("obj_preview", ID_obj_preview)
	{
		InitMembers();
		preview_event_create(ScopeAny(this->id));
	}
	
	obj_recent::obj_recent()
		: Object("obj_recent", ID_obj_recent)
	{
		InitMembers();
		recent_event_create(Scope<obj_recent>(this));
	}
	
	obj_recent::~obj_recent()
	{
		recent_event_destroy(Scope<obj_recent>(this));
	}
	
	obj_resource::obj_resource()
		: Object("obj_resource", ID_obj_resource)
	{
		InitMembers();
		res_event_create(Scope<obj_resource>(this));
	}
	
	obj_resource::~obj_resource()
	{
		res_event_destroy(ScopeAny(this->id));
	}
	
	obj_scrollbar::obj_scrollbar()
		: Object("obj_scrollbar", ID_obj_scrollbar)
	{
		InitMembers();
		scrollbar_event_create(Scope<obj_scrollbar>(this));
	}
	
	obj_shader::obj_shader()
		: Object("obj_shader", ID_obj_shader)
	{
		InitMembers();
	}
	
	obj_sortlist::obj_sortlist()
		: Object("obj_sortlist", ID_obj_sortlist)
	{
		InitMembers();
		sortlist_event_create(Scope<obj_sortlist>(this));
	}
	
	obj_tab::obj_tab()
		: Object("obj_tab", ID_obj_tab)
	{
		InitMembers();
		tab_event_create(Scope<obj_tab>(this));
	}
	
	obj_template::obj_template()
		: Object("obj_template", ID_obj_template)
	{
		InitMembers();
		temp_event_create(ScopeAny(this->id));
	}
	
	obj_template::~obj_template()
	{
		temp_event_destroy(ScopeAny(this->id));
	}
	
	obj_textbox::obj_textbox()
		: Object("obj_textbox", ID_obj_textbox)
	{
		InitMembers();
	}
	
	obj_theme::obj_theme()
		: Object("obj_theme", ID_obj_theme)
	{
		InitMembers();
	}
	
	obj_timeline::obj_timeline()
		: Object("obj_timeline", ID_obj_timeline)
	{
		InitMembers();
		tl_event_create(Scope<obj_timeline>(this));
	}
	
	obj_timeline::~obj_timeline()
	{
		tl_event_destroy(ScopeAny(this->id));
	}
	
	obj_toast::obj_toast()
		: Object("obj_toast", ID_obj_toast)
	{
		InitMembers();
		toast_event_create(Scope<obj_toast>(this));
	}
	
	obj_toast::~obj_toast()
	{
		toast_event_destroy(Scope<obj_toast>(this));
	}
	
	obj_videoquality::obj_videoquality()
		: Object("obj_videoquality", ID_obj_videoquality)
	{
		InitMembers();
	}
	
	obj_videotemplate::obj_videotemplate()
		: Object("obj_videotemplate", ID_obj_videotemplate)
	{
		InitMembers();
	}
	
	obj_view::obj_view()
		: Object("obj_view", ID_obj_view)
	{
		InitMembers();
		view_event_create(Scope<obj_view>(this));
	}
	
	micro_animation::micro_animation(StringType name)
		: Object("micro_animation", ID_micro_animation)
	{
		InitMembers();
		ds_list_add({ global::microani_list, id });
		ds_map_add(global::microanis, name, id);
		key = name;
		steps_alive = IntType(0);
		steps_hidden = IntType(0);
		active = (new value_animation())->id;
		hover = (new value_animation())->id;
		holding = (new value_animation())->id;
		disable = (new value_animation())->id;
		custom = (new value_animation())->id;
		fade = (new value_animation())->id;
		ObjType(value_animation, fade)->init(IntType(1));
		goal_value = IntType(0);
		goal_ease = IntType(0);
	}
	
	void micro_animation::update(RealType spd)
	{
		if (ObjType(value_animation, hover)->value_ani_linear != ObjType(value_animation, hover)->value || ObjType(value_animation, active)->value_ani_linear != ObjType(value_animation, active)->value || ObjType(value_animation, holding)->value_ani_linear != ObjType(value_animation, holding)->value || ObjType(value_animation, disable)->value_ani_linear != ObjType(value_animation, disable)->value || ObjType(value_animation, custom)->value_ani_linear != ObjType(value_animation, custom)->value || ObjType(value_animation, fade)->value_ani_linear != ObjType(value_animation, fade)->value)
		{
			ObjType(value_animation, active)->update(spd);
			ObjType(value_animation, hover)->update(spd);
			ObjType(value_animation, holding)->update(spd);
			ObjType(value_animation, disable)->update(spd);
			ObjType(value_animation, custom)->update(spd);
			ObjType(value_animation, fade)->update(spd);
		}
		if (goal_ease != goal_value)
		{
			if (global::_app->setting_reduced_motion > 0)
				goal_ease = goal_value;
			else
			{
				RealType valadd = (goal_value - goal_ease) / max({ IntType(1), 3.0 / global::delta });
				goal_ease += valadd;
				if (abs(valadd) < 0.01)
					goal_ease = goal_value;
				goal_ease = clamp(goal_ease, IntType(0), IntType(1));
			}
			
		}
	}
	
	value_animation::value_animation()
		: Object("value_animation", ID_value_animation)
	{
		InitMembers();
		init(IntType(0));
	}
	
	void value_animation::init(VarType val)
	{
		value = val;
		value_prev = val;
		value_ani_linear = val;
		value_ani_ease = val;
		value_base = val;
		value_offset = val;
		value_ani_offset = val;
		value_ani_offset_ease = val;
		value_goal = val;
	}
	
	RealType value_animation::update(RealType spd)
	{
		if (value_ani_linear == value)
			return IntType(0);
		if (global::_app->setting_reduced_motion > 0)
		{
			value_ani_linear = value;
			value_ani_ease = value;
			value_base = value_ani_linear;
			value_prev = value;
			value_offset = 0.0;
			value_ani_offset = 0.0;
		}
		else
		{
			if (value != value_prev)
			{
				value_base = value_ani_linear;
				value_prev = value;
				value_ani_offset = 0.0;
				value_goal = value;
				if (!(value > 0))
					value_offset = -value_base;
				else
					value_offset = 1.0 - value_base;
				
			}
			value_ani_offset += spd * global::delta;
			value_ani_offset_ease = ease(/*"easeoutcirc"*/ STR(557), value_ani_offset);
			value_ani_offset = clamp(value_ani_offset, IntType(0), IntType(1));
			value_ani_linear = value_base + (value_offset * value_ani_offset);
			value_ani_linear = clamp(value_ani_linear, IntType(0), IntType(1));
			value_ani_ease = value_base + (value_offset * value_ani_offset_ease);
			value_ani_ease = clamp(value_ani_ease, IntType(0), IntType(1));
		}
		
		return 0.0;
	}
	
	frustum::frustum()
		: Object("frustum", ID_frustum)
	{
		InitMembers();
		active = true;
		vbuffer = null_;
		corners = array_create({ IntType(8), vec4(IntType(0)) });
		near_ = IntType(0);
		far_ = IntType(0);
		matView = null_;
		matProj = null_;
		matBias = null_;
		clipEndDepth = IntType(0);
		reset();
	}
	
	void frustum::reset()
	{
		p[IntType(0)] = ArrType::From({ IntType(1), IntType(0), IntType(0), IntType(1) });
		p[IntType(1)] = ArrType::From({ -IntType(1), IntType(0), IntType(0), IntType(1) });
		p[IntType(2)] = ArrType::From({ IntType(0), IntType(1), IntType(0), IntType(1) });
		p[IntType(3)] = ArrType::From({ IntType(0), -IntType(1), IntType(0), IntType(1) });
		p[IntType(4)] = ArrType::From({ IntType(0), IntType(0), IntType(1), IntType(1) });
		p[IntType(5)] = ArrType::From({ IntType(0), IntType(0), -IntType(1), IntType(1) });
	}
	
	void frustum::build(VarType matVP, RealType ortho)
	{
		MatrixType matVPt = matrix_transpose(matVP);
		MatrixType matVPi = matrix_inverse(matVP);
		reset();
		for (IntType i = IntType(0); i < IntType(6); i++)
		{
			VecType mul = vec4_mul_matrix(p.Value(i), matVPt);
			p[i] = vec4_div(mul, vec3_length(vec3(mul.Real(X_), mul.Real(Y_), mul.Real(Z_))));
		}
		ArrType corners_v4;
		RealType near_;
		near_ = ((ortho > 0) ? -IntType(1) : IntType(0));
		corners_v4 = ArrType::From({ ArrType::From({ -IntType(1), IntType(1), IntType(1), IntType(1) }), ArrType::From({ IntType(1), IntType(1), IntType(1), IntType(1) }), ArrType::From({ IntType(1), -IntType(1), IntType(1), IntType(1) }), ArrType::From({ -IntType(1), -IntType(1), IntType(1), IntType(1) }), ArrType::From({ -IntType(1), IntType(1), near_, IntType(1) }), ArrType::From({ IntType(1), IntType(1), near_, IntType(1) }), ArrType::From({ IntType(1), -IntType(1), near_, IntType(1) }), ArrType::From({ -IntType(1), -IntType(1), near_, IntType(1) }) });
		for (IntType i = IntType(0); i < IntType(8); i++)
		{
			corners[i] = vec4_homogenize(vec4_mul_matrix(corners_v4.Value(i), matVPi));
			corners[i][W_] = IntType(1);
		}
	}
	
	void frustum::add_triangle(IntType corner1, IntType corner2, IntType corner3)
	{
		vbuffer_add_triangle({ corners.Value(corner1), corners.Value(corner2), corners.Value(corner3), ArrType::From({ IntType(0), IntType(0) }), ArrType::From({ IntType(0), IntType(0) }), ArrType::From({ IntType(0), IntType(0) }) });
	}
	
	void frustum::build_vbuffer(IntType color)
	{
		if (vbuffer != null_)
			vbuffer_destroy(vbuffer);
		global::vertex_emissive = IntType(1);
		global::vertex_alpha = 0.5;
		vbuffer_start();
		global::vertex_rgb = color_multiply(color, c_dkgrey);
		add_triangle(IntType(0), IntType(4), IntType(5));
		add_triangle(IntType(5), IntType(1), IntType(0));
		global::vertex_rgb = color_multiply(color, c_ltgrey);
		add_triangle(IntType(7), IntType(3), IntType(2));
		add_triangle(IntType(2), IntType(6), IntType(7));
		global::vertex_rgb = color_multiply(color, c_grey);
		add_triangle(IntType(2), IntType(1), IntType(5));
		add_triangle(IntType(5), IntType(6), IntType(2));
		add_triangle(IntType(7), IntType(4), IntType(0));
		add_triangle(IntType(0), IntType(3), IntType(7));
		global::vertex_rgb = color;
		add_triangle(IntType(0), IntType(1), IntType(2));
		add_triangle(IntType(2), IntType(3), IntType(0));
		add_triangle(IntType(4), IntType(7), IntType(6));
		add_triangle(IntType(6), IntType(5), IntType(4));
		vbuffer = vbuffer_done();
		global::vertex_emissive = IntType(0);
		global::vertex_alpha = IntType(1);
		global::vertex_rgb = c_white;
	}
	
	void access_error()
	{
		show_message(/*"There was an error with the Mine-imator startup.\n"*/ STR(1) + /*"Make sure you have administrative rights (Right click->Run as administrator) or try re-installing the program in a different location."*/ STR(2));
	}
	
	RealType action_background_ambient_color(ScopeAny self, VarType color)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
		{
			if (action_tl_select_single(self, { null_, e_tl_type_BACKGROUND }))
			{
				tl_value_set_start(self, ID_action_background_ambient_color, true);
				tl_value_set(self, e_value_BG_AMBIENT_COLOR, color, false);
				tl_value_set_done();
				return IntType(0);
			}
			history_set_var(self, ID_action_background_ambient_color, sVar(background_ambient_color), color, true);
		}
		sVar(background_ambient_color) = color;
		return 0.0;
	}
	
	RealType action_background_biome(ScopeAny self, VarType biome)
	{
		IntType biomeobj = find_biome(biome);
		if (ObjType(obj_biome, biomeobj)->group > 0)
			biome = ObjType(obj_biome, DsList(ObjType(obj_biome, biomeobj)->biome_variants).Value(IntType(0)))->name;
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
		{
			if (action_tl_select_single(self, { null_, e_tl_type_BACKGROUND }))
			{
				tl_value_set_start(self, ID_action_background_biome, true);
				tl_value_set(self, e_value_BG_BIOME, biome, false);
				tl_value_set_done();
				return IntType(0);
			}
			history_set_var(self, ID_action_background_biome, sVar(background_biome), biome, true);
		}
		sVar(background_biome) = biome;
		withAll (obj_resource, self->id)
			res_update_colors(ScopeAny(self));
		
		ObjType(obj_preview, ObjType(obj_category, ObjType(obj_tab, sInt(properties))->library)->preview)->update = true;
		return 0.0;
	}
	
	RealType action_background_fog_color(ScopeAny self, VarType color)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
		{
			if (action_tl_select_single(self, { null_, e_tl_type_BACKGROUND }))
			{
				tl_value_set_start(self, ID_action_background_fog_color, true);
				tl_value_set(self, e_value_BG_FOG_COLOR, color, false);
				tl_value_set_done();
				return IntType(0);
			}
			history_set_var(self, ID_action_background_fog_color, sVar(background_fog_color), color, true);
		}
		sVar(background_fog_color) = color;
		return 0.0;
	}
	
	RealType action_background_fog_color_custom(ScopeAny self, VarType custom)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
		{
			if (action_tl_select_single(self, { null_, e_tl_type_BACKGROUND }))
			{
				tl_value_set_start(self, ID_action_background_fog_color_custom, true);
				tl_value_set(self, e_value_BG_FOG_CUSTOM_COLOR, custom, false);
				tl_value_set_done();
				return IntType(0);
			}
			history_set_var(self, ID_action_background_fog_color_custom, sVar(background_fog_color_custom), custom, false);
		}
		sVar(background_fog_color_custom) = custom;
		return 0.0;
	}
	
	RealType action_background_fog_custom_object_color(ScopeAny self, VarType custom)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
		{
			if (action_tl_select_single(self, { null_, e_tl_type_BACKGROUND }))
			{
				tl_value_set_start(self, ID_action_background_fog_custom_object_color, true);
				tl_value_set(self, e_value_BG_FOG_CUSTOM_OBJECT_COLOR, custom, false);
				tl_value_set_done();
				return IntType(0);
			}
			history_set_var(self, ID_action_background_fog_custom_object_color, sVar(background_fog_custom_object_color), custom, false);
		}
		sVar(background_fog_custom_object_color) = custom;
		return 0.0;
	}
	
	RealType action_background_fog_distance(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
		{
			if (action_tl_select_single(self, { null_, e_tl_type_BACKGROUND }))
			{
				tl_value_set_start(self, ID_action_background_fog_distance, true);
				tl_value_set(self, e_value_BG_FOG_DISTANCE, val, add);
				tl_value_set_done();
				return IntType(0);
			}
			history_set_var(self, ID_action_background_fog_distance, sVar(background_fog_distance), sVar(background_fog_distance) * add + val, true);
		}
		sVar(background_fog_distance) = sVar(background_fog_distance) * add + val;
		return 0.0;
	}
	
	RealType action_background_fog_height(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
		{
			if (action_tl_select_single(self, { null_, e_tl_type_BACKGROUND }))
			{
				tl_value_set_start(self, ID_action_background_fog_height, true);
				tl_value_set(self, e_value_BG_FOG_HEIGHT, val, add);
				tl_value_set_done();
				return IntType(0);
			}
			history_set_var(self, ID_action_background_fog_height, sVar(background_fog_height), sVar(background_fog_height) * add + val, true);
		}
		sVar(background_fog_height) = sVar(background_fog_height) * add + val;
		return 0.0;
	}
	
	RealType action_background_fog_object_color(ScopeAny self, VarType color)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
		{
			if (action_tl_select_single(self, { null_, e_tl_type_BACKGROUND }))
			{
				tl_value_set_start(self, ID_action_background_fog_object_color, true);
				tl_value_set(self, e_value_BG_FOG_OBJECT_COLOR, color, false);
				tl_value_set_done();
				return IntType(0);
			}
			history_set_var(self, ID_action_background_fog_object_color, sVar(background_fog_object_color), color, true);
		}
		sVar(background_fog_object_color) = color;
		return 0.0;
	}
	
	RealType action_background_fog_show(ScopeAny self, VarType show)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
		{
			if (action_tl_select_single(self, { null_, e_tl_type_BACKGROUND }))
			{
				tl_value_set_start(self, ID_action_background_fog_show, true);
				tl_value_set(self, e_value_BG_FOG_SHOW, show, false);
				tl_value_set_done();
				return IntType(0);
			}
			history_set_var(self, ID_action_background_fog_show, sVar(background_fog_show), show, false);
		}
		sVar(background_fog_show) = show;
		return 0.0;
	}
	
	RealType action_background_fog_size(ScopeAny self, VarType val, VarType add)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
		{
			if (action_tl_select_single(self, { null_, e_tl_type_BACKGROUND }))
			{
				tl_value_set_start(self, ID_action_background_fog_size, true);
				tl_value_set(self, e_value_BG_FOG_SIZE, val, add);
				tl_value_set_done();
				return IntType(0);
			}
			history_set_var(self, ID_action_background_fog_size, sVar(background_fog_size), sVar(background_fog_size) * add + val, true);
		}
		sVar(background_fog_size) = sVar(background_fog_size) * add + val;
		return 0.0;
	}
	
	RealType action_background_fog_sky(ScopeAny self, VarType show)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
		{
			if (action_tl_select_single(self, { null_, e_tl_type_BACKGROUND }))
			{
				tl_value_set_start(self, ID_action_background_fog_sky, true);
				tl_value_set(self, e_value_BG_FOG_SKY, show, false);
				tl_value_set_done();
				return IntType(0);
			}
			history_set_var(self, ID_action_background_fog_sky, sVar(background_fog_sky), show, false);
		}
		sVar(background_fog_sky) = show;
		return 0.0;
	}
	
	RealType action_background_foliage_color(ScopeAny self, VarType color)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
		{
			if (action_tl_select_single(self, { null_, e_tl_type_BACKGROUND }))
			{
				tl_value_set_start(self, ID_action_background_foliage_color, true);
				tl_value_set(self, e_value_BG_FOLIAGE_COLOR, color, false);
				tl_value_set_done();
				return IntType(0);
			}
			history_set_var(self, ID_action_background_foliage_color, sVar(background_foliage_color), color, true);
		}
		sVar(background_foliage_color) = color;
		withAll (obj_resource, self->id)
			res_update_colors(ScopeAny(self));
		
		ObjType(obj_preview, ObjType(obj_category, ObjType(obj_tab, sInt(properties))->library)->preview)->update = true;
		return 0.0;
	}
	
	RealType action_background_grass_color(ScopeAny self, VarType color)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
		{
			if (action_tl_select_single(self, { null_, e_tl_type_BACKGROUND }))
			{
				tl_value_set_start(self, ID_action_background_grass_color, true);
				tl_value_set(self, e_value_BG_GRASS_COLOR, color, false);
				tl_value_set_done();
				return IntType(0);
			}
			history_set_var(self, ID_action_background_grass_color, sVar(background_grass_color), color, true);
		}
		sVar(background_grass_color) = color;
		withAll (obj_resource, self->id)
			res_update_colors(ScopeAny(self));
		
		ObjType(obj_preview, ObjType(obj_category, ObjType(obj_tab, sInt(properties))->library)->preview)->update = true;
		return 0.0;
	}
	
	RealType action_background_ground_show(ScopeAny self, VarType show)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
		{
			if (action_tl_select_single(self, { null_, e_tl_type_BACKGROUND }))
			{
				tl_value_set_start(self, ID_action_background_ground_show, true);
				tl_value_set(self, e_value_BG_GROUND_SHOW, show, false);
				tl_value_set_done();
				return IntType(0);
			}
			history_set_var(self, ID_action_background_ground_show, sVar(background_ground_show), show, false);
		}
		sVar(background_ground_show) = show;
		return 0.0;
	}
	
	RealType action_background_ground_slot(ScopeAny self, VarType slot)
	{
		if (!(sReal(history_undo) > 0) && !(sReal(history_redo) > 0))
		{
			if (action_tl_select_single(self, { null_, e_tl_type_BACKGROUND }))
			{
				tl_value_set_start(self, ID_action_background_ground_slot, true);
				tl_value_set(self, e_value_BG_GROUND_SLOT, slot, false);
				tl_value_set_done();
				return IntType(0);
			}
			history_set_var(self, ID_action_background_ground_slot, sVar(background_ground_slot), slot, true);
		}
		sVar(background_ground_slot) = slot;
		background_ground_update_texture(self);
		background_ground_update_texture_normal(self);
		background_ground_update_texture_material(self);
		return 0.0;
	}
	
	RealType action_background_ground_tex(ScopeAny self, IntType res)
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
					res = new_res(self, fn, e_res_type_BLOCK_SHEET);
					withOne (Object, res, self->id)
						res_load(self);
					
				}
				history_set_res(self, ID_action_background_ground_tex, fn, sVar(background_ground_tex), res);
			}
		
		
		idInt(sVar(background_ground_tex), count)--;
		sVar(background_ground_tex) = res;
		idInt(sVar(background_ground_tex), count)++;
		background_ground_update_texture(self);
		return 0.0;
	}
	
	RealType action_background_ground_tex_material(ScopeAny self, IntType res)
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
					res = new_res(self, fn, e_res_type_BLOCK_SHEET);
					withOne (Object, res, self->id)
						res_load(self);
					
				}
				history_set_res(self, ID_action_background_ground_tex_material, fn, sVar(background_ground_tex_material), res);
			}
		
		
		idInt(sVar(background_ground_tex_material), count)--;
		sVar(background_ground_tex_material) = res;
		idInt(sVar(background_ground_tex_material), count)++;
		background_ground_update_texture_material(self);
		return 0.0;
	}
	
	RealType action_background_ground_tex_normal(ScopeAny self, IntType res)
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
					res = new_res(self, fn, e_res_type_BLOCK_SHEET);
					withOne (Object, res, self->id)
						res_load(self);
					
				}
				history_set_res(self, ID_action_background_ground_tex_normal, fn, sVar(background_ground_tex_normal), res);
			}
		
		
		idInt(sVar(background_ground_tex_normal), count)--;
		sVar(background_ground_tex_normal) = res;
		idInt(sVar(background_ground_tex_normal), count)++;
		background_ground_update_texture_normal(self);
		return 0.0;
	}
	
}
