/* * * * * * * * * * * * * * * * * * * *
 *                                     *
 *            M I N T R I X            *
 *           by Janik Heiler           *
 *                                     *
 * * * * * * * * * * * * * * * * * * * */

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

#ifndef MINTRIX_WEBPAGE_GameControl
#define MINTRIX_WEBPAGE_GameControl
namespace MintrixWeb
{

Webpage gamecontrol = {
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
      <button onclick='clicked("u")' style='border-bottom-left-radius: 0; border-bottom-right-radius: 0;'></button>
      <div></div>
      <button onclick='clicked("l")' style='border-top-right-radius: 0; border-bottom-right-radius: 0;'></button>
      <button onclick='clicked("c")' style='border-radius: 0;'></button>
      <button onclick='clicked("r")' style='border-bottom-left-radius: 0; border-top-left-radius: 0;'></button>
      <div></div>
      <button onclick='clicked("d")' style='border-top-left-radius: 0; border-top-right-radius: 0;'></button>
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

.script_js = "function clicked(name) {xhr = new XMLHttpRequest();xhr.open('POST', '/data/?btn=' + name);xhr.setRequestHeader('Content-Type', 'text/plain');xhr.send();}"
};

}
#endif
