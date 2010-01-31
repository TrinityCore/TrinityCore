-- adding spell requied for Totem of Wrath-Rank 2,3,4
DELETE FROM `spell_required` WHERE `spell_id` IN (57720,57721,57722);
INSERT INTO `spell_required` (`spell_id`,`req_spell`) VALUES
(57720,30706), -- Totem of Wrath rank 2 (must know rank 1)
(57721,57720), -- Totem of Wrath rank 3 (must know rank 2)
(57722,57721); -- Totem of Wrath rank 4 (must know rank 3)
