-- move missing pathids in template_addon
UPDATE `creature_template_addon` SET `path_id`=(`path_id` << 3);
