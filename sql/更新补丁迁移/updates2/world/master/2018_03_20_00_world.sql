-- Chief Engineer Foote SAI
SET @Entry := 34754;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@Entry;
DELETE FROM smart_scripts WHERE entryorguid=@Entry AND source_type=0;
INSERT INTO smart_scripts (entryorguid,source_type,id,link,event_type,event_phase_mask,event_chance,event_flags,event_param1,event_param2,event_param3,event_param4,action_type,action_param1,action_param2,action_param3,action_param4,action_param5,action_param6,target_type,target_param1,target_param2,target_param3,target_x,target_y,target_z,target_o,comment) VALUES
(@Entry,0,0,0,62,0,100,512,10556,0,0,0,56,46827,1,0,0,0,0,7,0,0,0,0,0,0,0,"Chief Engineer Foote - On Gossip Option 0 Selected - Add Item '46827'");
