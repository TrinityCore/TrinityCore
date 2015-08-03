-- Lost Drakkari Spirit SAI fix
UPDATE `smart_scripts` SET `event_param1`=0,`event_param2`=15 WHERE `entryorguid`=29129 AND `id`=4;
UPDATE `smart_scripts` SET `event_param1`=30,`event_param2`=100 WHERE `entryorguid`=29129 AND `id`=8;
