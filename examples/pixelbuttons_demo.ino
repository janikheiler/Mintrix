#include <Mintrix.h>
#include <Mintrix/Webpage_PixelButtons.h>

void handler()
{
  if(!Mintrix.hasArg("short"))
  {
    Mintrix.send(200);
    return;
  }

  switch(Mintrix.arg("short")[0])
  {
    case '0': Mintrix[40] = CRGB::Black; break;
    case '1': Mintrix[40] = CRGB::White; break;
    case 'r': Mintrix[40] = CRGB::Red;   break;
    case 'g': Mintrix[40] = CRGB::Green; break;
    case 'b': Mintrix[40] = CRGB::Blue;  break;
  }

  Mintrix.show();
  Mintrix.send(200);
}

void setup()
{
  delay(1000);
  Mintrix.clear();
  Mintrix.show();
  Serial.begin(19200); // idk why, but without this it doesn't work LOL (but i'm working on that)
  delay(1000);
  Mintrix.staticWiFi("Mx-WiFi");
  Mintrix.startWeb();
  Mintrix.setWebPage(MintrixWeb::pixelbuttons);
  Mintrix.onData(handler);
}

void loop()
{
  Mintrix.handleWeb();
}