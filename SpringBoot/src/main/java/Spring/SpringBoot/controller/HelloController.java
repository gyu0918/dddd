package Spring.SpringBoot.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class HelloController {

    @GetMapping("hello")
    public String hello(Model model){
        model.addAttribute("data", "hello!!");
        return "hello";
    }

    @GetMapping("hello-mvc")
    public String helloMvc(@RequestParam("name") String name, Model model){   //name부분에 값을 넣어주어야 한다.
        model.addAttribute("name", name);
        return "hello-template";
    }
    //  localhost:8080/hello-mvc?name=넣고싶은문자   이런식으로 값을 직접 넣어줘서 만든다.


    @GetMapping("hello-string")
    @ResponseBody      // http에서 헤더부와 바디부에서 바디부에 밑의 데이터를 직접 넣어주겠다는 것
    public String helloString(@RequestParam("name") String name){
        return "hello " + name;
    }


    @GetMapping("hello-api")
    @ResponseBody
    public Hello helloApi(@RequestParam("name") String name){
        Hello hello = new Hello();
        hello.setName(name);
        return hello;         //여기에서 @ResponseBody에서 return hello처럼 객체를 리턴해준다면 디폴트로 json으로 반환하는걸로 세팅되어있음
    }

    static class Hello{
        private String name;

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }
    }
}
