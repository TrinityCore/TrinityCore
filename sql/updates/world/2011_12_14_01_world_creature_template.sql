-- Set standard immunities to The Nexus bosses.

-- Grand Magus Telestra:
UPDATE `creature_template` SET `mechanic_immune_mask`=617561983 WHERE `entry` IN (26731, 30510);
-- Anomalus:
UPDATE `creature_template` SET `mechanic_immune_mask`=617561983 WHERE `entry` IN (26763, 30529);
-- Ormorok the Tree-Shaper:
UPDATE `creature_template` SET `mechanic_immune_mask`=617561983 WHERE `entry` IN (26794, 30532);
-- Keristrasza:
UPDATE `creature_template` SET `mechanic_immune_mask`=617561983 WHERE `entry` IN (26723, 30540);
-- Commander Stoutbeard:
UPDATE `creature_template` SET `mechanic_immune_mask`=617561983 WHERE `entry` IN (26796, 30398);
-- Commander Kolurg:
UPDATE `creature_template` SET `mechanic_immune_mask`=617561983 WHERE `entry` IN (26798, 30397);
