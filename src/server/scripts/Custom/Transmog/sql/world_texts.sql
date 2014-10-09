SET @TEXT_ID := 50000;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES
(@TEXT_ID, 'La transmogirification vous permet de changer l`apparence de vos objets sans perdre leurs caractéristique.\r\nLes objets transmogrifiers ne sont pas remboursé, ni changeable, il sont verrouillez a vous.\r\nPas tous les objets sont transmogrifiables, il`y a certaines limitations, mais par contre, vous pouvez transmogirifier les armes, et les stuff.\r\nComment ça fonctionne?\r\nVous devez procurer deux items, celui que vous voulez garder ces caractéristiques, vous devez le porter! celui que vous voulez garder sont affichage vous le devez gardez dans votre sac! et vous faite la transmogrification!\r\nla transmogrification s'annule si l'un des deux objets nécessaires pour la procédure et déplacer du chez vous exp. vers la banque!\r\nvous pouvez a tout moment supprimer la transmogrification, et faire une autre.\r\n'),
(@TEXT_ID+1, 'Vous pouvez sauvegarder tout vos sets transmogrifier.\r\nSauvegarder d`abord vos items transmorgifier.\r\nAprès, cliquer sur Gestion des sets -> Sauvegarder le set\r\nTous les objets que vous avez transmorgifier sont afficher pour que vous voire ce que vous sauvegarder.\r\nSi vous pensez que votre set est bon, vous pouvez cliquer sur Sauvegarder le set le le nommer.\r\n');

SET @STRING_ENTRY := 11100;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(@STRING_ENTRY+0, 'Objet transmogifier'),
(@STRING_ENTRY+1, 'Equipment slot is empty'),
(@STRING_ENTRY+2, 'Objet source invalide'),
(@STRING_ENTRY+3, 'Objet source inexistant'),
(@STRING_ENTRY+4, 'Destination d`objet inexistante'),
(@STRING_ENTRY+5, 'Objet selectionner invalide'),
(@STRING_ENTRY+6, 'Pas accé d`argent'),
(@STRING_ENTRY+7, 'Vous avez pas des TOKEN sufisantes!'),
(@STRING_ENTRY+8, 'Transmogrifications supprimer'),
(@STRING_ENTRY+9, 'Vous avez pas transmogrifications'),
(@STRING_ENTRY+10, 'Nom invalide');
