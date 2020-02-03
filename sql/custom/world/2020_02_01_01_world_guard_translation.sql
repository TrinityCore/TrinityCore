delete gmol from gossip_menu_option_locale gmol where gmol.MenuID in (
select MenuID from gossip_menu_option gmo
where gmo.OptionText='The auction house'
and gmo.OptionID = gmol.OptionID
and gmol.Locale = 'frFR');

insert into gossip_menu_option_locale (
select MenuID, OptionID, 'frFR' as Local, 'Hotel des ventes', BoxText
from gossip_menu_option
where OptionText='The auction house'
);

delete gmol from gossip_menu_option_locale gmol where gmol.MenuID in (
select MenuID from gossip_menu_option gmo
where gmo.OptionText='The guild master'
and gmo.OptionID = gmol.OptionID
and gmol.Locale = 'frFR');

insert into gossip_menu_option_locale (
select MenuID, OptionID, 'frFR' as Local, 'Maître de guilde', BoxText
from gossip_menu_option
where OptionText='The guild master'
);

delete gmol from gossip_menu_option_locale gmol where gmol.MenuID in (
select MenuID from gossip_menu_option gmo
where OptionText='The mailbox'
and gmo.OptionID = gmol.OptionID
and gmol.Locale = 'frFR');

insert into gossip_menu_option_locale (
select MenuID, OptionID, 'frFR' as Local, 'Boîte aux lettres', BoxText
from gossip_menu_option
where OptionText='The mailbox'
);

delete gmol from gossip_menu_option_locale gmol where gmol.MenuID in (
select MenuID from gossip_menu_option gmo
where OptionText='The weapon master'
and gmo.OptionID = gmol.OptionID
and gmol.Locale = 'frFR');

insert into gossip_menu_option_locale (
select MenuID, OptionID, 'frFR' as Local, 'Maître d''armes', BoxText
from gossip_menu_option
where OptionText='The weapon master'
);