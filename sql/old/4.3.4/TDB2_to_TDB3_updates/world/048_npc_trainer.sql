-- Currently the alliance version of Portal: Tol Barad (88345) spell requires level 96 to learn should be level 85 like the horde counter part.
UPDATE `npc_trainer` SET `reqlevel`=85 WHERE `entry`=200200 AND `spell`=88345;
