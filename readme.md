<div class="d-flex mb-3 px-3 px-md-4 px-lg-5">
  <div class="flex-auto min-width-0 width-fit mr-3">
      <h1 class="d-flex flex-wrap flex-items-center break-word f3 text-normal">
        <span itemprop="name" class="ml-2 flex-self-stretch">Argumentative</span>
        <span class="mr-2 flex-self-stretch">
          <a class="flex-shrink-0 d-none d-md-inline"
             href="https://travis-ci.com/ViralTaco/Argumentative">
            <img src="https://travis-ci.com/ViralTaco/Argumentative.svg?branch=master">
          </a>
        </span>  
      </h1>
    </div>
  </div>
</div>  
A simple command line agrument parser for C++.

## Getting Started
### Prerequisites

* [CMake](https://cmake.org) 
* git

### Installing 

#### As a library:
Coming soon. 

#### Adding it to your code:
Download [vt_argumentative.hpp](./vt_argumentative.hpp).
Add it to you project. For example in a folder named `include`.

Include the header to your .cpp file containing you main function.
```c++
#include "vt_argumentative.hpp"
// […]
int main(int argc, char** argv) {
  using namespace ive;
  // Define your arguments
  Argumentative app(argc, argv);
  // Use it…
}
```
### Example
For a full example check out [example.cpp](./example.cpp).
```c++
// Includes…
int main(int argc, char** argv) {
  ive::Help help; // default help message.
  ive::Version version("1.0.0");
  ive::Argumentative app(argc, argv, { help, version });

  for (auto const& arg: app) {
    if (arg == version) {
      std::cout << app.version();
    } else {
      std::cout << app.usage();
    }
  }
}
```
## Running the tests

Run `ArgumentativeTests`

## Deployment

This library is in beta. Please avoid using it in production. 
Or do so at your own discretion.

## Contributing

 1. Fork
 2. Code (if you add a feature don't forget to write tests for it)
 3. Test 
 4. Add and commit (if possible: each file individually)
 5. Push to your remote
 6. Make a pull request on this repo.

## Versioning

We use [SemVer](http://semver.org/) for versioning. 
For the versions available, see the [tags on this repository](https://github.com/ViralTaco/Argumentative/tags). 

## Authors

* **Anthony Capobianco** - *Initial work* - 
[viraltaco_](https://github.com/ViralTaco)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - 
see [MIT](https://opensource.org/licenses/MIT) for more information.

## Acknowledgments

* [PurpleBooth](https://github.com/PurpleBooth/) for their `README.md` [template](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2)
* [Viatorus](https://github.com/Viatorus) for [quom](https://github.com/Viatorus/quom) for the single header tool.
* [The LLVM Foundation](http://llvm.org/foundation/) for [clang-format](https://clang.llvm.org/docs/ClangFormat.html) 
