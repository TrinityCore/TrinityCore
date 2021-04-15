-- Template updates for creature 30081 (Efrem the Faithful)
UPDATE `creature_template` SET `npcflag`=`npcflag`|1 WHERE `entry`=30081; -- Efrem the Faithful
-- Model data 26827 (creature 30081 (Efrem the Faithful))
UPDATE `creature_model_info` SET `bounding_radius`=0.3672,`combat_reach`=1.8,`gender`=0 WHERE `modelid`=26827; -- Efrem the Faithful
