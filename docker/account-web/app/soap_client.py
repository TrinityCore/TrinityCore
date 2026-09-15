"""Minimal client for TrinityCore worldserver's SOAP command interface
(src/server/worldserver/TCSoap/TCSoap.cpp) - just enough to call
ns1:executeCommand and read back its result or fault text. No SOAP/WSDL
library: the interface is a single fixed operation, and TCSoap.cpp expects
plain HTTP Basic Auth credentials (it reads them off soap->userid/passwd,
which gSOAP populates from the Authorization header), so httpx alone is
enough - same dependency ai-server's own model_provider.py already uses.
"""
from __future__ import annotations

import xml.etree.ElementTree as ET
from dataclasses import dataclass

import httpx

_SOAP_NS = {"SOAP-ENV": "http://schemas.xmlsoap.org/soap/envelope/", "ns1": "urn:TC"}

_ENVELOPE_TEMPLATE = """<?xml version="1.0" encoding="UTF-8"?>
<SOAP-ENV:Envelope xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/" xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
<SOAP-ENV:Body>
<ns1:executeCommand xmlns:ns1="urn:TC">
<command>{command}</command>
</ns1:executeCommand>
</SOAP-ENV:Body>
</SOAP-ENV:Envelope>"""


class SoapCommandError(Exception):
    """The command reached worldserver but it reported failure (a SOAP
    fault - wrong gmlevel on the calling account, command rejected by
    TrinityCore, TCP-level auth failure via 401/403, ...). The fault text
    is TrinityCore's own, safe to show the operator as-is.
    """


class SoapUnavailable(Exception):
    """worldserver's SOAP endpoint could not be reached at all (network
    error, timeout) - distinct from SoapCommandError so callers can tell
    "worldserver is down" apart from "the command was rejected".
    """


@dataclass(frozen=True)
class SoapConfig:
    url: str
    username: str
    password: str
    timeout_seconds: float = 10.0


def _escape(text: str) -> str:
    return (
        text.replace("&", "&amp;")
        .replace("<", "&lt;")
        .replace(">", "&gt;")
    )


def parse_response(status_code: int, text: str) -> str:
    """Pure parse step, split out from execute_command so tests can drive
    it directly against canned TrinityCore responses instead of a real (or
    mocked-transport) HTTP round trip.
    """
    if status_code in (401, 403):
        raise SoapCommandError(
            "worldserver rejected the account-web SOAP credentials "
            "(TC_SOAP_USER/TC_SOAP_PASSWORD) - see README_DEV.md 'Account creation web UI'"
        )

    try:
        root = ET.fromstring(text)
    except ET.ParseError as exc:
        raise SoapUnavailable(f"worldserver returned an unparseable SOAP response: {exc}") from exc

    fault = root.find(".//SOAP-ENV:Fault", _SOAP_NS)
    if fault is not None:
        faultstring = fault.findtext("faultstring", default="unknown SOAP fault")
        detail = fault.findtext("detail", default="")
        raise SoapCommandError(faultstring if not detail else f"{faultstring}: {detail}")

    result = root.find(".//ns1:executeCommandResponse/result", _SOAP_NS)
    if result is None or result.text is None:
        return ""
    return result.text


def execute_command(config: SoapConfig, command: str, client: httpx.Client | None = None) -> str:
    """Runs one TrinityCore console command (e.g. "account create foo bar")
    as the configured SOAP account and returns its result text. Raises
    SoapCommandError on a SOAP fault / non-2xx, SoapUnavailable if the
    request couldn't be sent or parsed at all. `client` is injectable so
    tests can pass an httpx.Client(transport=httpx.MockTransport(...))
    instead of hitting a real worldserver.
    """
    body = _ENVELOPE_TEMPLATE.format(command=_escape(command)).encode("utf-8")
    headers = {
        "Content-Type": 'text/xml; charset="utf-8"',
        "SOAPAction": "urn:TC#executeCommand",
    }

    owns_client = client is None
    http_client = client or httpx.Client()
    try:
        response = http_client.post(
            config.url,
            content=body,
            headers=headers,
            auth=(config.username, config.password),
            timeout=config.timeout_seconds,
        )
    except httpx.HTTPError as exc:
        raise SoapUnavailable(f"could not reach worldserver SOAP endpoint: {exc}") from exc
    finally:
        if owns_client:
            http_client.close()

    return parse_response(response.status_code, response.text)
