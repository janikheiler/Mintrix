/* * * * * * * * * * * * * * * * * * * *
 *                                     *
 *            M I N T R I X            *
 *           by Janik Heiler           *
 *                                     *
 * * * * * * * * * * * * * * * * * * * */

#include "Mintrix.h"

// CMintrix instance
CMintrix Mintrix;

CMintrix::CMintrix() : _server_(80)
{
  // initiate fastled things
  FastLED.addLeds<WS2812B, MINTRIX_PIN, GRB>(leds, num_leds);
  FastLED.setBrightness(100);
  FastLED.setCorrection(UncorrectedColor);
  FastLED.setTemperature(UncorrectedTemperature);
  FastLED.clear();
  FastLED.show();
}

void CMintrix::connect(String wifi_ssid, String wifi_pswd)
{
	if(wifi_pswd == "") WiFi.begin(wifi_ssid);
	else WiFi.begin(wifi_ssid, wifi_pswd);
}

void CMintrix::staticWiFi(String wifi_ssid, String wifi_pswd)
{
  WiFi.mode(WIFI_AP);
	WiFi.softAPConfig(IPAddress(10, 10, 10, 1), IPAddress(10, 10, 10, 1), IPAddress(255, 255, 255, 0));

  _wifi_ssid_ = wifi_ssid;
  _wifi_pswd_ = (wifi_pswd.length() > 7) ? wifi_pswd : "";

  if(_wifi_pswd_ == "")  WiFi.softAP(_wifi_ssid_);
	else                   WiFi.softAP(_wifi_ssid_, _wifi_pswd_);
}

void CMintrix::dynamicWiFi_start(String wifi_pswd)
{
	_wifi_pswd_ = (wifi_pswd.length() > 7) ? wifi_pswd : "";
	WiFi.scanNetworks(true);
}

int CMintrix::dynamicWiFi_state()
{
  if(_mintrix_id_ > -1)
    return _mintrix_id_;

  int wsc = WiFi.scanComplete();
  if(wsc < 0)
    return wsc; // -1: still searching, -2: hasnt started yet

  _mintrix_id_ = 0;
  for(int i = 0; i < wsc; i++)
    if(WiFi.SSID(i) == "Mintrix Nr. " + (String)_mintrix_id_)
    {
      _mintrix_id_ += 1;
      i = -1;
    }
  
  _wifi_ssid_ = "Mintrix Nr. " + (String)_mintrix_id_;
  if(_wifi_pswd_ == "") WiFi.softAP(_wifi_ssid_);
	else                  WiFi.softAP(_wifi_ssid_, _wifi_pswd_);
  return _mintrix_id_;
}

void CMintrix::startWeb(String domain_name = "", bool domain = true)
{
	_has_domain_ = domain;
	_domain_name_ = (domain_name == "") ? MINTRIX_DOMAIN : domain_name;
	if(_has_domain_) _dns_.start(53, _domain_name_, IPAddress(10, 10, 10, 1));
	
	_server_.onNotFound([](){Mintrix.send(404);});
	_server_.begin();

	_server_.on("/",          [](){Mintrix.send(200, "text/html",       Mintrix.getPageHTML());});
	_server_.on("/style.css", [](){Mintrix.send(200, "text/css",        Mintrix.getStyleCSS());});
	_server_.on("/script.js", [](){Mintrix.send(200, "text/javascript", Mintrix.getScriptJS());});
}
