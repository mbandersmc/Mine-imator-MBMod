/// block_load(map)
/// @arg map

var map = argument0;

with (new(obj_block))
{
	// Name
	if (is_string(map[?"name"]))
		name = map[?"name"]
	else
	{
		log("Could not find name for block")
		return null
	}
	
	// Type (overridden by states)
	if (is_string(map[?"type"]))
		type = map[?"type"]
	else
		type = ""
	
	// File
	if (is_string(map[?"file"]))
		file = block_load_state_file(map[?"file"], type)
	else
		file = null
			
	// Brightness (overridden by states)
	if (is_real(map[?"brightness"]))
		brightness = map[?"brightness"]
	else
		brightness = 1
	
	// Read states and their possible values
	states_map = null
	if (is_real(map[?"states"]) && ds_exists(map[?"states"], ds_type_map))
	{
		states_map = ds_map_create()
		var curstate = ds_map_find_first(map[?"states"]);
		while (!is_undefined(curstate))
		{
			with (new(obj_block_state))
			{
				var values_ = ds_map_find_value(map[?"states"], curstate);
				value_amount = 0
				
				// String of | separated values
				if (is_string(values_))
				{
					var valuesarr = string_split(values_, "|");
					for (var v = 0; v < array_length_1d(valuesarr); v++)
					{
						value_name[v] = valuesarr[v]
						value_file[v] = null
						value_type[v] = ""
						value_brightness[v] = null
						value_amount++
					}
				}
				
				// Map with attributes for each value
				else
				{
					var curvalue = ds_map_find_first(values_);
					while (!is_undefined(curvalue))
					{
						var curvaluemap = values_[?curvalue];
						
						value_name[value_amount] = curvalue
						value_file[value_amount] = null
						value_type[value_amount] = ""
						value_brightness[value_amount] = null
						
						if (ds_exists(curvaluemap, ds_type_map))
						{
							// File
							if (!is_undefined(curvaluemap[?"file"]))
								value_file[value_amount] = block_load_state_file(curvaluemap[?"file"], other.type)
								
							// Type
							if (is_string(curvaluemap[?"type"]))
								value_type[value_amount] = curvaluemap[?"type"]
							
							// Brightness
							if (is_real(curvaluemap[?"brightness"]))
								value_brightness[value_amount] = curvaluemap[?"brightness"]
						}
						
						curvalue = ds_map_find_next(values_, curvalue)
						value_amount++
					}
				}
				
				other.states_map[?curstate] = id
				curstate = ds_map_find_next(map[?"states"], curstate)
			}
		}
	}
	
	// Default state
	if (is_string(map[?"default_state"]))
	{
		default_state = map[?"default_state"]
		default_state_map = ds_map_create()
		block_vars_string_to_map(default_state, default_state_map)
	}
	else
	{
		default_state = ""
		default_state_map = null
	}
	
	// Wind
	var windmap = map[?"wind"];
	wind_axis = e_vertex_wave.NONE
	wind_zroot = null
	if (is_real(windmap) && ds_exists(windmap, ds_type_map))
	{
		if (is_string(windmap[?"axis"]))
		{
			if (windmap[?"axis"] = "y")
				wind_axis = e_vertex_wave.Z_ONLY
			else
				wind_axis = e_vertex_wave.ALL
		}
		
		if (is_real(windmap[?"yroot"]))
			wind_zroot = windmap[?"yroot"]
	}
	
	// Requires render models
	if (is_real(map[?"require_models"]))
		require_models = map[?"require_models"]
	else
		require_models = false
	
	// Legacy data
	for (var d = 0; d < 16; d++)
	{
		legacy_data_state_map[d] = null
		legacy_data_state[d] = ""
	}
		
	// Read data list into maps
	if (is_real(map[?"legacy_data"]) && ds_exists(map[?"legacy_data"], ds_type_map))
		block_load_legacy_data_map(map[?"legacy_data"], 0, 1)
	
	// Convert maps to strings
	for (var d = 0; d < 16; d++)
	{
		if (legacy_data_state_map[d] != null)
		{
			legacy_data_state[d] = block_vars_map_to_string(legacy_data_state_map[d])
			ds_map_destroy(legacy_data_state_map[d])
		}
	}
	
	return id
}