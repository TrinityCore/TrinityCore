-- Rut'theran Village, Teldrassil and Auberdine, Darkshore ("The Moonspray")
DELETE FROM `transports` WHERE `guid`=3;

-- Remove creatures of the transport
DELETE FROM `creature_transport` WHERE `transport_entry`=176244;
