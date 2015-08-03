DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (35637, 35633, 35768, 34658, 35636, 35638, 35635, 35640, 35641, 35634, 35491);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(35637, 34705, 0, 0, 'Marshal Jacob Alerius'' Mount - Marshal Jacob Alerius <Grand Champion of Stormwind>', 8, 0),
(35633, 34702, 0, 0, 'Ambrose Boltspark''s Mount - Ambrose Boltspark', 8, 0),
(35768, 34701, 0, 0, 'Colosos'' Mount - Colosos', 8, 0),
(34658, 34657, 0, 0, 'Jaelyne Evensong''s Mount - Jaelyne Evensong', 8, 0),
(35636, 34703, 0, 0, 'Lana Stouthammer''s Mount - Lana Stouthammer <Grand Champion of Ironforge>', 8, 0),

(35638, 35572, 0, 0, 'Mokra the Skullcrusher''s Mount - Mokra the Skullcrusher <Grand Champion of Orgrimmar>', 8, 0),
(35635, 35569, 0, 0, 'Eressea Dawnsinger''s Mount - Eressea Dawnsinger', 8, 0),
(35640, 35571, 0, 0, 'Runok Wildmane''s Mount - Runok Wildmane', 8, 0),
(35641, 35570, 0, 0, 'Zul''tore''s Mount - Zul''tore', 8, 0),
(35634, 35617, 0, 0, 'Deathstalker Visceri''s Mount - Deathstalker Visceri', 8, 0),

(35491, 35451, 0, 0, 'Black Knight''s Skeletal Gryphon - The Black Knight', 8, 0);


DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (35637, 35633, 35768, 34658, 35636, 35638, 35635, 35640, 35641, 35634, 35491);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(35637, 46598, 0, 0),
(35633, 46598, 0, 0),
(35768, 46598, 0, 0),
(34658, 46598, 0, 0),
(35636, 46598, 0, 0),

(35638, 46598, 0, 0),
(35635, 46598, 0, 0),
(35640, 46598, 0, 0),
(35641, 46598, 0, 0),
(35634, 46598, 0, 0),

(35491, 46598, 0, 0);
