-- Master Shang Xi(Creature Guid:940754) was not in the same phase as the player when logging in.

UPDATE `creature` SET `phaseMask` = '1'  WHERE `guid` = '940754' ;

-- Delete Double Spawned Jaomin Ro
DELETE FROM `creature` WHERE `guid` = '996832' ;

-- Fix Scriptname for Jaomin Ro
UPDATE `creature_template` SET `ScriptName` = 'boss_jaomin_ro' WHERE `entry` = '54611' ;

-- Master Li Fei(Creature Guid:996300) Should not spawned and hostile. 
DELETE FROM `creature` WHERE `guid` = '996300' ;
