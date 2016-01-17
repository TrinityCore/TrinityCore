--
UPDATE `creature` SET `PhaseId`=169 WHERE `phaseMask`=1 AND `PhaseGroup`=0;
UPDATE `creature` SET `PhaseId`=170 WHERE `phaseMask`=2 AND `PhaseGroup`=0;
UPDATE `creature` SET `PhaseId`=171 WHERE `phaseMask`=4 AND `PhaseGroup`=0;
UPDATE `creature` SET `PhaseId`=172 WHERE `phaseMask`=8 AND `PhaseGroup`=0;
UPDATE `creature` SET `PhaseId`=173 WHERE `phaseMask`=16 AND `PhaseGroup`=0;
UPDATE `creature` SET `PhaseId`=174 WHERE `phaseMask`=32 AND `PhaseGroup`=0;
UPDATE `creature` SET `PhaseId`=175 WHERE `phaseMask`=64 AND `PhaseGroup`=0;
UPDATE `creature` SET `PhaseId`=176 WHERE `phaseMask`=128 AND `PhaseGroup`=0;
UPDATE `creature` SET `PhaseId`=177 WHERE `phaseMask`=256 AND `PhaseGroup`=0;
UPDATE `creature` SET `PhaseGroup`=371 WHERE `phaseMask`=3;
UPDATE `creature` SET `PhaseGroup`=396 WHERE `phaseMask`=5;
UPDATE `creature` SET `PhaseGroup`=368 WHERE `phaseMask`=7;
UPDATE `creature` SET `PhaseGroup`=392 WHERE `phaseMask`=10;
UPDATE `creature` SET `PhaseGroup`=391 WHERE `phaseMask`=17; --   = 1+16    =  173 + 169
UPDATE `creature` SET `PhaseGroup`=394 WHERE `phaseMask`=66; --   = 64+2    =  175 + 170
UPDATE `creature` SET `PhaseGroup`=408 WHERE `phaseMask`=69; --   = 64+4+1  =  175 + 171 + 169
UPDATE `creature` SET `PhaseGroup`=375 WHERE `phaseMask`=129; --  = 128+1   =  176 + 169
UPDATE `creature` SET `PhaseGroup`=404 WHERE `phaseMask`IN (131,255); --  = 128+64+32+16+8+4+2+1 = 176 + 170 + 169    -- 131 changed to 255
UPDATE `creature` SET `PhaseGroup`=369 WHERE `phaseMask`=192; --  = 128 + 64    = 175 + 176
UPDATE `creature` SET `PhaseGroup`=397 WHERE `phaseMask`=193; --  = 128 + 64 + 1= 175 + 176 +169
 
--
UPDATE `gameobject` SET `PhaseId`=169 WHERE `phaseMask`=1 AND `PhaseGroup`=0;
UPDATE `gameobject` SET `PhaseId`=170 WHERE `phaseMask`=2 AND `PhaseGroup`=0;
UPDATE `gameobject` SET `PhaseId`=171 WHERE `phaseMask`=4 AND `PhaseGroup`=0;
UPDATE `gameobject` SET `PhaseId`=172 WHERE `phaseMask`=8 AND `PhaseGroup`=0;
UPDATE `gameobject` SET `PhaseId`=173 WHERE `phaseMask`=16 AND `PhaseGroup`=0;
UPDATE `gameobject` SET `PhaseId`=174 WHERE `phaseMask`=32 AND `PhaseGroup`=0;
UPDATE `gameobject` SET `PhaseId`=175 WHERE `phaseMask`=64 AND `PhaseGroup`=0;
UPDATE `gameobject` SET `PhaseId`=176 WHERE `phaseMask`=128 AND `PhaseGroup`=0;
UPDATE `gameobject` SET `PhaseId`=177 WHERE `phaseMask`=256 AND `PhaseGroup`=0;
UPDATE `gameobject` SET `PhaseGroup`=371 WHERE `phaseMask`=3;
UPDATE `gameobject` SET `PhaseGroup`=396 WHERE `phaseMask`=5;
UPDATE `gameobject` SET `PhaseGroup`=368 WHERE `phaseMask`=7;
UPDATE `gameobject` SET `PhaseGroup`=392 WHERE `phaseMask`=10;
 
UPDATE `creature` SET `PhaseId`=169 WHERE `PhaseId`=1 AND `PhaseGroup`=0;
UPDATE `creature` SET `PhaseId`=172 WHERE `PhaseId`=8 AND `PhaseGroup`=0;
UPDATE `creature` SET `PhaseId`=174 WHERE `PhaseId`=32 AND `PhaseGroup`=0;
UPDATE `creature` SET `PhaseId`=175 WHERE `PhaseId`=64 AND `PhaseGroup`=0;
