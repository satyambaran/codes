let { Configuration, OpenAIApi } = require("openai");

async function func() {
    console.log(process.env.OPENAI_API_KEY)
    const configuration = new Configuration({
        apiKey: "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",
    });
    const openai = new OpenAIApi(configuration);

    try {
        const completion = await openai.createCompletion({
            model: "text-davinci-003",
            prompt: "write a code in c++ to generate fibonacci number",
        });
        console.log(completion.data);
    } catch (error) {
        if (error.response) {
            console.log(error.response.status);
            console.log(error.response.data);
        } else {
            console.log(error.message);
        }
    }
    return "success";
}
func().then((res) => {
    console.log(res);
});
