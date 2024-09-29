/* * * * * * * * * * * * * * * * * * * *
 *                                     *
 *            M I N T R I X            *
 *           by Janik Heiler           *
 *                                     *
 * * * * * * * * * * * * * * * * * * * */

#ifndef MINTRIX_H
#define MINTRIX_H

// Mintrix version number as integer
// 1 digit for major version
// 3 digits for minor version
// 3 digits for patch version
#define MINTRIX_VERSION 1001001

// config
#define MINTRIX_PIN 2
#define MINTRIX_DOMAIN "web.mintrix"

// extern libraries
#include "Arduino.h"
#include "DNSServer.h"
#include "ESP8266WebServer.h"
#include "ESP8266WiFi.h"
#include "FastLED.h"

//CRGB operator*(double r, CRGB c) {return CRGB(c.r * r, c.g * r, c.b * r);}
//CRGB operator*(CRGB c, double r) {return CRGB(c.r * r, c.g * r, c.b * r);}

#ifndef MINTRIXWEB
#define MINTRIXWEB
namespace MintrixWeb
{
	struct Webpage {
		String page_html;
		String style_css;
		String script_js;
	};
}
#endif

class CMintrix
{
  private:
    // wifi
    int _mintrix_id_ = -1;
    String _wifi_ssid_ = "";
    String _wifi_pswd_ = "";
    bool _has_domain_ = false;
    String _domain_name_ = "";

    // web
    DNSServer _dns_;
    ESP8266WebServer _server_;
    MintrixWeb::Webpage _web_page_ = {.page_html = "<h1>Mintrix!</h1>", .style_css = "", .script_js = ""};

  public:
    CMintrix();

    // physical properties
    const int width = 9;
    const int height = 9;
    const int num_leds = 81;

    // leds
    CRGB leds[81];
    CRGB& operator[](int i) {return leds[i % num_leds];};

    // standard fast-led things
    void show() {FastLED.show();};
    void clear() {FastLED.clear();};
    void fill(const struct CRGB &color) {fill_solid(leds, 81, color);}

    // wifi
    void connect(String wifi_ssid, String wifi_pswd);
    void staticWiFi(String wifi_ssid, String wifi_pswd = "");
    void dynamicWiFi_start(String wifi_pswd = "");
    int dynamicWiFi_state();
		int id() {return _mintrix_id_;};

    // web
    void startWeb(String domain_name = "", bool domain = true);
    void handleWeb() {_dns_.processNextRequest(); _server_.handleClient();};
    void onData(void (*handler)()) {_server_.on("/data/",  handler); _server_.on("/data",  handler);};

    void setWebPage(MintrixWeb::Webpage wp) {_web_page_ = wp;};
    String getPageHTML() {return _web_page_.page_html;};
    String getStyleCSS() {return _web_page_.style_css;};
    String getScriptJS() {return _web_page_.script_js;};

    // access incoming data from web
		String uri()                    {return _server_.uri();       };
		String arg(const char *name)    {return _server_.arg(name);   };
		String arg(int i)               {return _server_.arg(i);      };
		String argName(int i)           {return _server_.argName(i);  };
		int    args()                   {return _server_.args();      };
		bool   hasArg(const char *name) {return _server_.hasArg(name);};

		// send response to incoming data from web
		void send(int code, const char*    content_type = NULL, const String & content = String("")) {_server_.send(code, content_type, content);};
		void send(int code, char*          content_type,        const String & content)              {_server_.send(code, content_type, content);};
		void send(int code, const String & content_type,        const String & content)              {_server_.send(code, content_type, content);};
};

extern CMintrix Mintrix;

#endif
