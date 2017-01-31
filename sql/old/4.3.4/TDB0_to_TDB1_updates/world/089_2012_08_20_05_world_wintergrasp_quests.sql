-- Wintergrasp Quests - Horde
UPDATE `quest_template` SET `ExclusiveGroup`=13180 WHERE `id` IN (13180,13178); -- Slay them all!
UPDATE `quest_template` SET `ExclusiveGroup`=13185 WHERE `id` IN (13185,13223); -- Stop/Defend the Siege
UPDATE `quest_template` SET `ExclusiveGroup`=13201 WHERE `id` IN (13201,13194); -- Healing with Roses
UPDATE `quest_template` SET `ExclusiveGroup`=13199 WHERE `id` IN (13193,13199); -- Bones and Arrows
UPDATE `quest_template` SET `ExclusiveGroup`=13192 WHERE `id` IN (13192,13202); -- Warding/Jinxing the Walls
UPDATE `quest_template` SET `ExclusiveGroup`=13200 WHERE `id` IN (13200,13191); -- Fueling the Demolishers

-- Wintergrasp Quests - Alliance
UPDATE `quest_template` SET `ExclusiveGroup`=13179 WHERE `id` IN (13179,13177); -- No Mercy for the Merciless
UPDATE `quest_template` SET `ExclusiveGroup`=13186 WHERE `id` IN (13186,13222); -- Stop/Defend the Siege
UPDATE `quest_template` SET `ExclusiveGroup`=13195 WHERE `id` IN (13195,13156); -- A Rare Herb
UPDATE `quest_template` SET `ExclusiveGroup`=13196 WHERE `id` IN (13196,13154); -- Bones and Arrows
UPDATE `quest_template` SET `ExclusiveGroup`=13198 WHERE `id` IN (13198,13153); -- Warding the Warriors

-- Note: The offered quests (they are in pairs) depend on who controls the keep. npc_wg_quest_giver does that already?
