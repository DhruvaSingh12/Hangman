<h1 align="center">Hangman Game - Periodic Table Edition</h1>

<p align="center">
  Welcome to the <strong>Hangman Game - Periodic Table Edition</strong>! This is a fun and educational command-line game where you guess the names of elements from the periodic table. The game randomly selects an element, and you have to guess its name letter by letter. The game features a hangman visual representation to track your incorrect guesses.
</p>

<h2>Features</h2>
<ul>
    <li><strong>Periodic Table Theme:</strong> The game focuses on guessing elements from the periodic table, making it both entertaining and educational.</li>
    <li><strong>Randomized Elements:</strong> Each round, the game selects a random element from the periodic table, keeping the game fresh and challenging.</li>
    <li><strong>Hangman Visuals:</strong> A simple yet effective ASCII representation of a hangman to show your progress and remaining attempts.</li>
    <li><strong>Score and Lives Tracking:</strong> The game tracks your score and remaining lives, providing a clear overview of your progress.</li>
    <li><strong>Cross-Platform Compatibility:</strong> The game is designed to work on both Windows and Unix-based systems.</li>
</ul>

<h2>How to Play</h2>
<ol>
    <li>The game will randomly select an element from the periodic table.</li>
    <li>You'll be prompted to guess letters in the name of the element.</li>
    <li>Each incorrect guess will add a part to the hangman.</li>
    <li>You win the round if you guess the element correctly before the hangman is fully drawn.</li>
    <li>The game ends if you run out of lives or guess all elements correctly.</li>
</ol>

<h2>Prerequisites</h2>
<p>C++ compiler (GCC, Clang, MSVC, etc.)</p>

<h2>How to Compile and Run</h2>
<pre>
<code>
git clone https://github.com/your-username/hangman-periodic-table.git
cd hangman-periodic-table
</code>
</pre>
<pre>
<code>
g++ -o hangman hangman.cpp
</code>
</pre>
<pre>
<code>
./hangman
</code>
</pre>

<h2>Customization</h2>
<p>You can customize the list of elements or the hangman visuals by modifying the code. The list of elements is stored in the <code>periodicTable</code> vector, and the hangman visuals are handled by the <code>printHangman()</code> function.</p>

<h2>Contributing</h2>
<p>Contributions are welcome! If you find any bugs or have suggestions for improvements, please feel free to create an issue or submit a pull request.</p>

<p align="center">
  <a href="https://github.com/your-username/hangman-periodic-table"><strong>View on GitHub</strong></a>
</p>
