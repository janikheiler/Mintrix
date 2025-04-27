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

#ifndef MINTRIX_WEBPAGE_Keyboard
#define MINTRIX_WEBPAGE_Keyboard
namespace MintrixWeb
{

Webpage keyboard = {
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
    <div id="main">
      <div class="row"><div id="ipt"></div></div>

      <div class="row">
        <button class="char" onclick="clickedchar(this.innerText)">1</button>
        <button class="char" onclick="clickedchar(this.innerText)">2</button>
        <button class="char" onclick="clickedchar(this.innerText)">3</button>
        <button class="char" onclick="clickedchar(this.innerText)">4</button>
        <button class="char" onclick="clickedchar(this.innerText)">5</button>
        <button class="char" onclick="clickedchar(this.innerText)">6</button>
        <button class="char" onclick="clickedchar(this.innerText)">7</button>
        <button class="char" onclick="clickedchar(this.innerText)">8</button>
        <button class="char" onclick="clickedchar(this.innerText)">9</button>
        <button class="char" onclick="clickedchar(this.innerText)">0</button>
      </div>

      <div class="row">
        <button class="char" onclick="clickedchar(this.innerText)">Q</button>
        <button class="char" onclick="clickedchar(this.innerText)">W</button>
        <button class="char" onclick="clickedchar(this.innerText)">E</button>
        <button class="char" onclick="clickedchar(this.innerText)">R</button>
        <button class="char" onclick="clickedchar(this.innerText)">T</button>
        <button class="char" onclick="clickedchar(this.innerText)">Z</button>
        <button class="char" onclick="clickedchar(this.innerText)">U</button>
        <button class="char" onclick="clickedchar(this.innerText)">I</button>
        <button class="char" onclick="clickedchar(this.innerText)">O</button>
        <button class="char" onclick="clickedchar(this.innerText)">P</button>
      </div>

      <div class="row">
        <button class="char" onclick="clickedchar(this.innerText)">A</button>
        <button class="char" onclick="clickedchar(this.innerText)">S</button>
        <button class="char" onclick="clickedchar(this.innerText)">D</button>
        <button class="char" onclick="clickedchar(this.innerText)">F</button>
        <button class="char" onclick="clickedchar(this.innerText)">G</button>
        <button class="char" onclick="clickedchar(this.innerText)">H</button>
        <button class="char" onclick="clickedchar(this.innerText)">J</button>
        <button class="char" onclick="clickedchar(this.innerText)">K</button>
        <button class="char" onclick="clickedchar(this.innerText)">L</button>
      </div>

      <div class="row">
        <button class="char" onclick="clickedchar(this.innerText)">Y</button>
        <button class="char" onclick="clickedchar(this.innerText)">X</button>
        <button class="char" onclick="clickedchar(this.innerText)">C</button>
        <button class="char" onclick="clickedchar(this.innerText)">V</button>
        <button class="char" onclick="clickedchar(this.innerText)">B</button>
        <button class="char" onclick="clickedchar(this.innerText)">N</button>
        <button class="char" onclick="clickedchar(this.innerText)">M</button>
      </div>

      <div class="row">
        <button class="func" style="width: 20rem;" onclick="clickedchar(' ')">Leerzeichen</button>
      </div>

      <div class="row">
        <button class="func" style="width: 15rem;" onclick="clickedfunc(0)">Alles Löschen</button>
        <button class="func" style="width: 15rem;" onclick="clickedfunc(1)">Löschen</button>
        <button class="func" style="width: 15rem;" onclick="clickedfunc(2)">Absenden</button>
      </div>
    </div>
  </body>
</html>

)=====",

.style_css = R"=====(
body {
    background: #333333;
}

#main {
    position: absolute;
    left: 50%;
    top: 50%;
    transform: translate(-50%, -50%);
}

#ipt {
    text-align: center;
    background: #f1fcf8;
    color: #242422;
    border: .15rem solid #c1c1be;
    border-radius: 0.2rem;
    height: 4rem;
    width: 30rem;
    line-height: 4rem;
    font-size: 20px;
    white-space: pre;
}

.row {
    display: flex;
    justify-content: center;
    gap: .7rem;
    margin: .7rem 0;
}

.char,
.func {
    background: #3f9752;
    color: #15321f;
    border: .15rem solid #c1c1be;
    border-radius: 0.2rem;
    height: 4rem;
    font-size: 20px;
}

.char {
    width: 4rem;
}

.func {
    padding: 0 2rem;
}

)=====",

.script_js = R"=====(
text = ""

function send() {
    xhr = new XMLHttpRequest();
    xhr.open('POST', '/data/?text=' + text);
    xhr.setRequestHeader('Content-Type', 'text/plain');
    xhr.send();
}

function clickedchar(c) {
    text = text + c
    document.getElementById("ipt").innerText = text
}

function clickedfunc(n) {
    if(n == 0) text = ""
    if(n == 1) text = text.substring(0, text.length - 1)
    if(n == 2) send()

    document.getElementById("ipt").innerText = text
}

)====="
};

}
#endif
 