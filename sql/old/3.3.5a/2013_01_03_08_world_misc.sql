-- remove the leverscript not non-existing doorscripts!
DELETE FROM `gameobject_scripts` WHERE `id` IN (26206,26197);
