from transformers import AutoTokenizer, AutoModelForCausalLM,AutoModelForSequenceClassification,pipeline,EncoderDecoderCache
from datasets import load_dataset, Audio
import gradio as gr


""" 
vision_classifier = pipeline(model="google/vit-base-patch16-224")
gr.Interface.from_pipeline(vision_classifier).launch()
preds = vision_classifier(
    images="https://huggingface.co/datasets/huggingface/documentation-images/resolve/main/pipeline-cat-chonk.jpeg"
)
preds = [{"score": round(pred["score"], 4), "label": pred["label"]} for pred in preds]
print(preds)
 """
# load dataset

dataset = load_dataset("yelp_review_full")
dataset["train"][100]
# Load model directly


tokenizer = AutoTokenizer.from_pretrained("deepseek-ai/DeepSeek-R1-Distill-Llama-8B")
model = AutoModelForCausalLM.from_pretrained("deepseek-ai/DeepSeek-R1-Distill-Llama-8B")
""" 
batch_sentences = [
    "But what about second breakfast?",
    "Don't think he knows about second breakfast, Pip.",
    "What about elevensies?",
]

encoded_input = tokenizer(batch_sentences,padding=True,truncation=True,return_tensors="pt")
print(encoded_input,"\n")
output=tokenizer.batch_decode(encoded_input["input_ids"])

print(output) """



def tokenize_function(examples):
    return tokenizer(examples["text"], padding="max_length", truncation=True)


tokenized_datasets = dataset.map(tokenize_function, batched=True)

small_train_dataset = tokenized_datasets["train"].shuffle(seed=42).select(range(1000))
small_eval_dataset = tokenized_datasets["test"].shuffle(seed=42).select(range(1000))






