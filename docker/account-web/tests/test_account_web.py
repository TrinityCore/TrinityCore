"""account-web tests. soap_client.parse_response is exercised directly
against canned TrinityCore SOAP responses (success/fault/auth-rejected) -
no network involved. main.py's /accounts route is exercised through
FastAPI's TestClient with get_soap_config overridden and
app.main.execute_command patched, so the route's own sequencing (create ->
addon -> gmlevel, rollback via delete on a later failure) is what's under
test, not any real SOAP round trip.
"""
import unittest
from unittest.mock import patch

from fastapi.testclient import TestClient

from app.main import app, get_soap_config
from app.soap_client import SoapCommandError, SoapConfig, SoapUnavailable, parse_response

_FAULT_RESPONSE = """<?xml version="1.0"?>
<SOAP-ENV:Envelope xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/">
<SOAP-ENV:Body>
<SOAP-ENV:Fault>
<faultcode>SOAP-ENV:Server</faultcode>
<faultstring>Account already exist!</faultstring>
</SOAP-ENV:Fault>
</SOAP-ENV:Body>
</SOAP-ENV:Envelope>"""

_SUCCESS_RESPONSE = """<?xml version="1.0"?>
<SOAP-ENV:Envelope xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/" xmlns:ns1="urn:TC">
<SOAP-ENV:Body>
<ns1:executeCommandResponse>
<result>Account created: TESTUSER</result>
</ns1:executeCommandResponse>
</SOAP-ENV:Body>
</SOAP-ENV:Envelope>"""


class ParseResponseTests(unittest.TestCase):
    def test_success_returns_result_text(self):
        self.assertEqual(parse_response(200, _SUCCESS_RESPONSE), "Account created: TESTUSER")

    def test_fault_raises_soap_command_error_with_faultstring(self):
        with self.assertRaises(SoapCommandError) as ctx:
            parse_response(200, _FAULT_RESPONSE)
        self.assertIn("Account already exist!", str(ctx.exception))

    def test_401_raises_soap_command_error(self):
        with self.assertRaises(SoapCommandError):
            parse_response(401, "")

    def test_unparseable_body_raises_soap_unavailable(self):
        with self.assertRaises(SoapUnavailable):
            parse_response(200, "not xml")


def _fake_config() -> SoapConfig:
    return SoapConfig(url="http://worldserver:7878", username="svc", password="svc")


class CreateAccountRouteTests(unittest.TestCase):
    def setUp(self):
        app.dependency_overrides[get_soap_config] = _fake_config
        self.client = TestClient(app)

    def tearDown(self):
        app.dependency_overrides.clear()

    def test_rejects_username_over_16_chars(self):
        response = self.client.post(
            "/accounts", data={"username": "x" * 17, "password": "pw", "admin": "", "northrend": ""}
        )
        self.assertIn("nejvýše", response.text)

    @patch("app.main.execute_command")
    def test_plain_player_account_creates_and_sets_expansion_only(self, mock_exec):
        mock_exec.return_value = "ok"
        response = self.client.post(
            "/accounts", data={"username": "newplayer", "password": "pw"}
        )
        self.assertEqual(response.status_code, 200)
        commands = [call.args[1] for call in mock_exec.call_args_list]
        self.assertEqual(commands, ["account create newplayer pw", "account set addon newplayer 1"])

    @patch("app.main.execute_command")
    def test_admin_with_northrend_sets_addon_2_and_gmlevel(self, mock_exec):
        mock_exec.return_value = "ok"
        response = self.client.post(
            "/accounts",
            data={"username": "gm", "password": "pw", "admin": "on", "northrend": "on"},
        )
        self.assertEqual(response.status_code, 200)
        commands = [call.args[1] for call in mock_exec.call_args_list]
        self.assertEqual(
            commands,
            [
                "account create gm pw",
                "account set addon gm 2",
                "account set gmlevel gm 3 -1",
            ],
        )

    @patch("app.main.execute_command")
    def test_addon_failure_rolls_back_created_account(self, mock_exec):
        def side_effect(config, command):
            if command.startswith("account set addon"):
                raise SoapCommandError("expansion rejected")
            return "ok"

        mock_exec.side_effect = side_effect
        response = self.client.post("/accounts", data={"username": "broken", "password": "pw"})

        self.assertEqual(response.status_code, 200)
        commands = [call.args[1] for call in mock_exec.call_args_list]
        self.assertEqual(
            commands,
            [
                "account create broken pw",
                "account set addon broken 1",
                "account delete broken",
            ],
        )
        self.assertIn("zrušen", response.text)

    @patch("app.main.execute_command")
    def test_create_failure_does_not_attempt_rollback(self, mock_exec):
        mock_exec.side_effect = SoapCommandError("Account already exist!")
        response = self.client.post("/accounts", data={"username": "dup", "password": "pw"})

        self.assertEqual(response.status_code, 200)
        self.assertEqual(mock_exec.call_count, 1)
        self.assertIn("Account already exist!", response.text)


if __name__ == "__main__":
    unittest.main()
