Suppose your primary db is called "world", and you have another db called "world2". By running world_merge_xxx.sql you can copy some spawn points which do not exist in "world" from "world2" to "world".

If you want to apply a update pack to "world", first run world_remove_merged_xxx to remove the merged spawn points of "world2" from "world", then apply update packet, then re-apply world_merge_xxx.sql. Make sure to do that clean up every time you use a update pack on "world" or "world2". Otherwise your db will be messed up.

Do not use these sql unless you can understand them.