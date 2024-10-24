--
UPDATE `creature_template_npcbot_wander_nodes` SET `flags`='4' WHERE (`id`='28'); -- Razor Hill: make Horde-only
-- Durotar canyon (Drygulch Ravine)
UPDATE `creature_template_npcbot_wander_nodes` SET `flags`='0' WHERE `id` IN ('66','1372','1373','1374','1375','1376','1377','1378','1380','1381','1382','1383','1384','1385','1401');
UPDATE `creature_template_npcbot_wander_nodes` SET `flags`='1' WHERE (`id`='419'); -- RefugePointeExitS: allow neutral spawns
UPDATE `creature_template_npcbot_wander_nodes` SET `flags`='1' WHERE (`id`='505'); -- LochS: allow neutral spawns
UPDATE `creature_template_npcbot_wander_nodes` SET `flags`='1' WHERE (`id`='1071'); -- AshenvaleC_hub11: allow neutral spawns
UPDATE `creature_template_npcbot_wander_nodes` SET `flags`='1' WHERE (`id`='1379'); -- DurotarCanyon1: allow neutral spawns
UPDATE `creature_template_npcbot_wander_nodes` SET `flags`='1' WHERE (`id`='1739'); -- DesolaceN34: allow neutral spawns
