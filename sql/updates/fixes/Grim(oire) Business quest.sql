-- Grim(oire) Business quest workaround.
-- TODO: Spawn only when player steps on Fire circle and SAI for Vim'gol abilities

-- Spawn Vim'gol the Vile by Expecto (untill a beter way is found)
SET @GUID :=xxxxx; -- set by TDB, need 1

DELETE FROM creature WHERE id=22911;
INSERT INTO creature (guid,id,map,spawnMask,phaseMask,modelid,equipment_id,position_x,position_y,position_z,orientation,spawntimesecs,spawndist,currentwaypoint,curhealth,curmana,MovementType,npcflag,unit_flags,dynamicflags) VALUES
(@GUID,22911,530,1,1,0,0,3279.73,4640.09,216.526,4.08274,300,0,0,97800,7196,0,0,0,0);

-- Spawn Vim'gol's Vile Grimoire wen NPC killed by nelegalno
UPDATE creature_template SET AIName='SmartAI' WHERE entry=22911;
DELETE FROM smart_scripts WHERE (entryorguid=22911 AND source_type=0);
INSERT INTO smart_scripts (entryorguid,source_type,id,link,event_type,event_phase_mask,event_chance,event_flags,event_param1,event_param2,event_param3,event_param4,action_type,action_param1,action_param2,action_param3,action_param4,action_param5,action_param6,target_type,target_param1,target_param2,target_param3,target_x,target_y,target_z,target_o,COMMENT) VALUES 
(22911,0,0,0,6,0,100,0,0,0,0,0,11,39862,2,0,0,0,0,1,0,0,0,0,0,0,0,"Vim'gol - Summon Vim'gol's Vile Grimoire Chest on Death");