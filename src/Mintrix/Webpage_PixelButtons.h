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

#ifndef MINTRIX_WEBPAGE_PixelButtons
#define MINTRIX_WEBPAGE_PixelButtons
namespace MintrixWeb
{

Webpage pixelbuttons = {
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
    <div id="buttons">
      <button onclick="clicked('black', '0')" style="background: #000000;"></button>
      <button onclick="clicked('white', '1')" style="background: #ffffff;"></button>
      <button onclick="clicked('red'  , 'r')" style="background: #ff0000;"></button>
      <button onclick="clicked('green', 'g')" style="background: #00ff00;"></button>
      <button onclick="clicked('blue' , 'b')" style="background: #0000ff;"></button>
    </div>
  </body>
</html>
)=====",

.style_css = R"=====(
body {
  background: #333333;
}

#buttons {
  display: grid;
  position: absolute;
  left: 50%;
  top: 50%;
  transform: translate(-50%, -50%);
  grid-template-columns: repeat(5, 15vw);
  grid-template-rows: 15vw;
  grid-gap: .7rem;
}

@media (orientation: portrait) {
  #buttons {
    grid-template-rows: repeat(5, 15vh);
    grid-template-columns: 15vh;
  }
}

button {
  border: .2rem solid #aaaaaa;
  border-radius: 7.5rem;
  aspect-ratio: 1 / 1;
}
)=====",

.script_js = "function clicked(name, nameshort) {xhr = new XMLHttpRequest();xhr.open('POST', '/data/?btn=' + name + '&short=' + nameshort);xhr.setRequestHeader('Content-Type', 'text/plain');xhr.send();}"
};

}
#endif
