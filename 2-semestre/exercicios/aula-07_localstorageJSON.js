const pokemonJSON = `
[
  { "nome": "Charmander" },
  { "nome": "Squirtle"},
  { "nome": "Bulbasaur" }
]
`;

let pokemons = JSON.parse(localStorage.getItem("pokemons")) || JSON.parse(pokemonJSON);

function salvarPokemons() {
  localStorage.setItem("pokemons", JSON.stringify(pokemons));
}

function listarPokemons() {
  const ul = document.getElementById("lista-pokemons");
  ul.innerHTML = "";

  pokemons.forEach(pokemon => {
    const li = document.createElement("li");
    li.textContent = pokemon.nome;
    ul.appendChild(li);
  });
}

function adicionarPokemon() {
  const nomeInput = document.getElementById("nome");
  const nome = nomeInput.value.trim();

  if(nome) {
    pokemons.push({ nome });
    salvarPokemons();
    listarPokemons();
    nomeInput.value = "";
  } else {
    alert("Digite o nome do Pokémon!");
  }
}

listarPokemons();