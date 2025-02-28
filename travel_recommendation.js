const result = document.getElementById("search-result");
const search_input = document.getElementById("search");
search_input.innerHTML = "";

function search_results() {
  fetch("json/travel_recommendation.json")
    .then((response) => response.json())
    .then((data) => {
      const countries = data.countries;
      const temples = data.temples;
      const beaches = data.beaches;
      console.log(beaches);
      console.log(temples);

      let c = countries.map((element) => element.cities);
      var citiesTemplesBeaches = [];
      c.forEach((element) => {
        element.forEach((city) => citiesTemplesBeaches.push(city));
      });

      temples.forEach((element) => citiesTemplesBeaches.push(element));
      beaches.forEach((element) => citiesTemplesBeaches.push(element));

      var result_cities = citiesTemplesBeaches
        .filter((element) =>
          element.name.toLowerCase().includes(search_input.value.toLowerCase())
        )
        .map(
          (element) =>
            `<div>
        <img src = "${element.imageUrl}">
        <div class = "search-info">
        <h1>${element.name}</h1>
        <p>${element.description}</p>
        <button>Visit</button>
        </div>
        </div>`
        );

      result.innerHTML = result_cities.join("");
    });
}

const searchbtn = document.querySelector(".search-btn");
searchbtn.addEventListener("click", search_results);

const clearBtn = document.querySelector(".search-btn:nth-child(3)"); // Selects the second search-btn (clear)

clearBtn.addEventListener("click", () => {
  search_input.value = "";
  result.innerHTML = "";
});
