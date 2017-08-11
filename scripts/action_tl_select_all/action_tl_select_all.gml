/// action_tl_select_all()

if (history_undo)
{
	with (history_data)
		history_restore_tl_select()
}
else
{
	if (!history_redo)
		with (history_set(action_tl_select_all))
			history_save_tl_select()
			
	for (var t = 0; t < tree_amount; t++)
		with (tree[t])
			tl_select()
}

app_update_tl_edit()