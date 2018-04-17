SET @Entry := 941;
UPDATE creature_template SET ScriptName = "", AIName="SmartAI" WHERE entry=@Entry;
DELETE FROM smart_scripts WHERE entryorguid=@Entry AND source_type=0;
INSERT INTO smart_scripts (entryorguid,source_type,id,link,event_type,event_phase_mask,event_chance,event_flags,event_param1,event_param2,event_param3,event_param4,action_type,action_param1,action_param2,action_param3,action_param4,action_param5,action_param6,target_type,target_param1,target_param2,target_param3,target_x,target_y,target_z,target_o,comment) VALUES
(@Entry,0,0,0,0,0,100,0,0,0,3500,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Kurzen Headshrinker - In Combat CMC - Cast 'Shadow Bolt'"),
(@Entry,0,1,0,0,0,100,0,2400,10800,39000,39500,11,7289,1,0,0,0,0,2,0,0,0,0,0,0,0,"Kurzen Headshrinker - In Combat - Cast 'Shrink'"),
(@Entry,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen Headshrinker - Between 0-15% Health - Flee For Assist (No Repeat)");
