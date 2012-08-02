-- hotfix for startup errors in YTDB 626
UPDATE `creature` SET `spawndist`='5', `MovementType`='1' WHERE `guid` in (48199,142619,142620,142621,142622);


