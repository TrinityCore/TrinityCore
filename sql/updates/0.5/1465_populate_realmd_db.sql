truncate realmd.realmlist;
insert into realmd.realmlist
select `id`, `name`, `address`, `icon`, `color`, `timezone` from mangos.realmlist;
drop table mangos.realmlist;

truncate realmd.account;
insert into realmd.account
select *,0 from mangos.account;
drop table mangos.account;

INSERT INTO RealmCharacters
SELECT realmlist.id, account.id, 0 from realmlist, account;

truncate realmd.ip_banned;
insert into realmd.ip_banned
select * from mangos.ip_banned;
drop table mangos.ip_banned;
