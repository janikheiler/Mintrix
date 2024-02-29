/* * * * * * * * * * * * * * * * * * * *
 *                                     *
 *            M I N T R I X            *
 *           by Janik Heiler           *
 *                                     *
 * * * * * * * * * * * * * * * * * * * */

#ifndef MINTRIX_WEB_H
#define MINTRIX_WEB_H
namespace MintrixWeb
{

// hello world!
#ifdef MINTRIX_HelloWorld
WebPage helloworld = {
  .page_html = "<h1>Hello World!</h1>",
  .style_css = "",
  .script_js = ""
};
#endif

// simple big button
#ifdef MINTRIX_BigButton
WebPage bigbutton = {
  .page_html = "<!DOCTYPE html><html><head><title>Mintrix</title><meta charset='utf-8'><link rel='shortcut icon' href='#'/><link rel='stylesheet' type='text/css' href='/style.css'><script type='text/javascript' src='/script.js'></script></head><body><button onclick='clicked()'>Drück mich!</button></body></html>",
  .style_css = "body {background: #000000;} button {font-size: 4rem; color: #000000; border: 1rem solid #ffffff; border-radius: 7.5rem; position: absolute; left: 50%; top: 50%; transform: translate(-50%, -50%); width: 80%; height: 80%;}",
  .script_js = "function clicked() {xhr = new XMLHttpRequest();xhr.open('POST', '/data/');xhr.setRequestHeader('Content-Type', 'text/plain');xhr.send();}"
};
#endif

// five buttons arranged in the shape of a plus
#ifdef MINTRIX_GameControl
WebPage gamecontrol = {
.page_html = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <title>Mintrix</title>
    <meta charset='utf-8'>
    <link rel='shortcut icon' href='#'/>
    <link rel='stylesheet' type='text/css' href='/style.css'>
    <script type='text/javascript' src='/script.js'></script>
  </head>
  <body>
    <div id='ctls'>
      <div></div>
      <button onclick='clicked(0)' style='border-bottom-left-radius: 0; border-bottom-right-radius: 0;'></button>
      <div></div>
      <button onclick='clicked(1)' style='border-top-right-radius: 0; border-bottom-right-radius: 0;'></button>
      <button onclick='clicked(2)' style='border-radius: 0;'></button>
      <button onclick='clicked(3)' style='border-bottom-left-radius: 0; border-top-left-radius: 0;'></button>
      <div></div>
      <button onclick='clicked(4)' style='border-top-left-radius: 0; border-top-right-radius: 0;'></button>
      <div></div>
    </div>
  </body>
</html>
)=====",

.style_css = R"=====(
body {
  background: #000000;
}

#ctls {
  display: grid;
  position: absolute;
  left: 50%;
  top: 50%;
  transform: translate(-50%, -50%);
  height: 80vh;
  width: 80vh;
  grid-template-columns: 4fr 3fr 4fr;
  grid-template-rows: 4fr 3fr 4fr;
  grid-gap: .7rem;
}

@media (orientation: portrait) {
  #ctls {
    height: 80vw;
    width: 80vw;
  }
}

button {
  border: .7rem solid #ffffff;
  border-radius: 7.5rem;
}
)=====",

.script_js = "function clicked(n) {xhr = new XMLHttpRequest();xhr.open('POST', '/data/?num=' + n);xhr.setRequestHeader('Content-Type', 'text/plain');xhr.send();}"
};
#endif

}
#endif

/* Standard HTTP-POST-request (js)
function send(d) {
  xhr = new XMLHttpRequest();
  xhr.open("POST", "/data/?" + d);
  xhr.setRequestHeader("Content-Type", "text/plain");
  xhr.send();
}
*/
