delete from spell_area where spell in (121164,121175,121176,121177);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(121164, 6051, 0, 0, 0, 0, 2, 0, 64, 11),
(121175, 6051, 0, 0, 0, 0, 2, 0, 64, 11),
(121176, 6051, 0, 0, 0, 0, 2, 0, 64, 11),
(121177, 6051, 0, 0, 0, 0, 2, 0, 64, 11);

delete from spell_script_names where ScriptName = 'spell_gen_orb_of_power';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(121164, 'spell_gen_orb_of_power'),
(121175, 'spell_gen_orb_of_power'),
(121176, 'spell_gen_orb_of_power'),
(121177, 'spell_gen_orb_of_power');

delete from trinity_string where entry >=1349 and entry <=1356;
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc8`) VALUES 
(1349, '$n ����������� |c0000ff00�������|r �����!', NULL),
(1350, '$n ����������� |c00a400ff����������|r �����!', NULL),
(1351, '$n ����������� |cFFFF8000���������|r �����!', NULL),
(1352, '$n ����������� |c0000ffca�����|r �����!', NULL),
(1353, '|c0000ff00�������|r ����� ����������!', NULL),
(1354, '|c00a400ff����������|r ����� ����������!', NULL),
(1355, '|cFFFF8000���������|r ����� ����������!', NULL),
(1356, '|c0000ffca�����|r ����� ����������!', NULL);