/// project_save_values(name, array, defaultarray)
/// @arg name
/// @arg array
/// @arg defaultarray

var name, arr ,defarr;
name = argument0
arr = argument1
defarr = argument2

json_export_object_start(name)

	for (var v = 0; v < e_value.amount; v++)
	{
		if (arr[@ v] != defarr[@ v])
		{
			if (tl_value_is_bool(v))
				json_export_var_bool(value_name_list[|v], arr[@ v])
			else if (tl_value_is_color(v))
				json_export_var_color(value_name_list[|v], arr[@ v])
			else
				json_export_var(value_name_list[|v], tl_value_get_save_id(v, arr[@ v]))
		}
	}
			
json_export_object_done()